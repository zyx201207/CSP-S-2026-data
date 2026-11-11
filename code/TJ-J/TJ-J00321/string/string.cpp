#include<iostream>
using namespace std;
struct node{
    int pl;
    char base;
};

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n,last_a = -1;
    long long ans = 0;
    bool easy = 1;
    node lst[200005];
    char tmp;
    string s;
    scanf("%d",&n);
    for(int i = 1;i <= n;i++){
        scanf("%d %c",&lst[i].pl,&lst[i].base);
        if(lst[i].pl != last_a && last_a != -1) easy = 0;
        last_a = lst[i].pl;
    }
    if(easy){
        for(int i = 1;i <= n/2;i++){
            if(lst[i].base != lst[n-i+1].base) ans += lst[i].pl;
        }
    }
    else{
        for(int i = 1;i <= n;i++){
            while(lst[i].pl--){
                s += lst[i].base;
            }
        }
        for(int i = 0;i <= (s.length()-1)/2-1;i++){
            if(s[i] != s[s.length()-i-1]) ans++;
        }
    }
    printf("%lld",ans);
    return 0;
}
