#include <bits/stdc++.h>
using namespace std;
int n,m,a[200005];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d",a+i);
    if(m==1)
        printf("%d",*max_element(a+1,a+n+1));
    else if(m==n){
        int adn=a[1];
        for(int i=2;i<=n;i++)
            adn&=a[i];
        printf("%d",adn);
    }
    return 0;
}
