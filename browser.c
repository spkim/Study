#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>
#define MAX_STR_LEN 512
#define BUFFER_SIZE 10000      
#define Get "GET /%s HTTP/1.0\r\nHost: %s\r\n\r\n"
#define Get1 "GET / HTTP/1.0\r\nHost: %s\r\n\r\n"   //identifier에 아무것도 입력하지 않고 엔터했을 경우
int main()
{
    int s, n, len_out;
    struct sockaddr_in server_addr;
 char szServer[MAX_STR_LEN];  //서버 URL
    char identifier[MAX_STR_LEN];  // 세부 파일명
 char szPort[10];
 char szStrRcv[BUFFER_SIZE];  //받은 파일
 char szStr[MAX_STR_LEN];
 char buff[MAX_STR_LEN];
    struct in_addr in;
 while(1) {
    printf("-----------------------\n");
 printf("Web server address :");
    fgets(szServer, MAX_STR_LEN, stdin);
    printf("\nSpecified file :");
    fgets(identifier, MAX_STR_LEN, stdin);
    printf("\n");
 strcpy(szPort, "80");
 
   
    //소켓 생성
    
 if ((s = socket(PF_INET, SOCK_STREAM, 0)) < 0)
    {
        printf("Can't create socket\n");
        exit(0);
    }
    else
        printf("Creat socket\n");       
    bzero((char*)&server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(szServer);
    server_addr.sin_port = htons(atoi(szPort));
   
    //서버에 접속
    
    if (connect(s, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0)
    {
        printf("Can't connect\n");
        exit(0);
    }   
    // 요청
    if(strcmp(identifier,"\n") == 0)      //identifier에 아무값도 입력하지 않고 엔터했을 경우
     sprintf(szStr, Get1, szServer);  //메소드와 URL HTTP 버전을 형식에 맞게 만들어줌
     else     
     sprintf(szStr, Get, identifier, szServer);   //메소드와 URL HTTP 버전을 형식에 맞게 만들어줌
     
    printf("REQUEST -------------------------\n");
    printf("%s", szStr);
    printf("---------------------------------\n");
 len_out = strlen(szStr);
    if (write(s, szStr, len_out) < 0)
    {
        printf("write error\n");
        exit(0);
    }

    /* 수신된 메세지 화면에 출력 */
 while(1) {
  memset(szStrRcv, '\0', BUFFER_SIZE);
  n = read(s, szStrRcv, BUFFER_SIZE);
  if(n == 0) {
       getchar();
       break;
        }      
  printf("%s", szStrRcv);
 }
    close(s); 
  }
  return 0;
}
