#include<bits/stdc++.h>
using namespace std;
int read(){
    int x=0,f=1;
    char c=getchar_unlocked();
    while(c<'0'||c>'9'){
        if(c=='-'){
            f=-1;
        }
        c=getchar_unlocked();
    }
    while(c>='0'&&c<='9'){
        x=x*10+c-'0';
        c=getchar_unlocked();
    }
    return x*f;
}
void write(int x){
    if(x<0){
        putchar('-');
        x=-x;
    }if(x>=10){
        write(x/10);
    }
    putchar(x%10+'0');
}
const int N=5e5+7,M=3e5+7;
int a[N],b[N],last[M],l[M];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n=read(),m=read();
    for(int i=1;i<=n;i++){
        a[i]=read();
        l[a[i]]=last[a[i]];
        last[a[i]]=i;
    }
    int uni=*max_element(l+1,l+1+m)+1;
    if(uni==1){
        for(int i=1;i<=m;i++){
            write(last[i]);
            putchar(' ');
        }
        return 0;
    }
    for(int i=1;i<=n;i++){
        if(i==uni){
            for(int j=1;j<=m;j++){
                b[j]+=max(0,last[j]-i+1);
            }
            break;
        }
        int j=i;
        while(j<=n){
            b[a[j]]++;
            j=last[a[j]]+1;
        }
    }
    for(int i=1;i<=m;i++){
        write(b[i]);
        putchar(' ');
    }
    return 0;
}
