//8:10  I came in,the desk was tooooo small,I alomst cannot fit my stuff in.After I opened CodeBlocks,I found a text on the desktop named "README",so I read it.
//I learned dijkstra and kruskal,but the test may not include them.The test use easier methods than dijkstra and kruskal,but it's hard to think of how to solve the problem.
//The hard part is think rather than programming.
//8:29  I opened the test.There are 4 tests,each has 100 points.
//8:45  I finished T1 (the first test) soooooooo easy!!! QwQ
//9:15  I finished T2.It works right when numbers are small,but wrong when numbers are big.HO NOOOOO!How can I deal it!!??!?
//9:34  HOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO I FOUND WHY I'M WORNG!!!!!And my program works PERFECT!!!!!!!!!SECOND PRIZE,HERE I COME!!!!!!!!!
//(You only have to finish 2 tests,and there's 90% to get second prize)
//T3 and T4 is the hardest test,it's almost impossible to get 100.However,you can get some of the points if your program works right when numbers are small.
//T4 seems eaiser to get more points,so I started to work on it.
//11:20 I finished T4,it took me a looooooooongggggggggg time.In the middle,I thought something was wrong,so I read the test again----I get wrong the meaning of the test!!!
//HONO T4 was wrong,even in small numbers.
#include <bits/stdc++.h>
using namespace std;
int r1,x1,r2,x2;
char rr,xx;

bool check(char a,char b){
    if((rr==a && xx==b) || (rr==b && xx==a))
        return 1;
    return 0;
}

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    scanf("%d%d",&r1,&r2);
    scanf(" %c",&rr);
    scanf("%d%d",&x1,&x2);
    scanf(" %c",&xx);
    if(rr=='D')
        rr='E';
    if(xx=='D')
        xx='E';
    if(r1!=x1){
        printf("0000");
        return 0;
    }
    if(r2!=x2){
        printf("1000");
        return 0;
    }
    if(check('A','B') || check('B','C') || check('E','F')){
        printf("1111");
        return 0;
    }
    printf("1110");
    return 0;
}
