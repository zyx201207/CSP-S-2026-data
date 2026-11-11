#include<bits/stdc++.h>
using namespace std;
mt19937 rnd(time(0));
int ttt;
int main() {
    while(1) {
        int T=1000;
        FILE* f=fopen("in","w");
        fprintf(f,"0 1000\n");
        while(T--) {
            int n=15, d=rnd()%120+1;
            fprintf(f,"%d %d\n",n,d);
            int x=0, d2=rnd()%20+1;
            for(int i=1; i<=n; i++) x+=rnd()%d2+1, fprintf(f,"%d ",x);
            fprintf(f,"\n");
        }
        fclose(f);
        system("./bl<in>ans"), system("./migrate<in>out");
        if(system("diff out ans")) return 1;
        ttt+=1000;
        printf("ok %d\n",ttt);
    }
}