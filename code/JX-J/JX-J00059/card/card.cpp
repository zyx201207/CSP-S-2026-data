#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],zs[500005];
int s[500005],top=0,sl[500005];
int main()
{
	freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++){
        memset(s,0,sizeof(s));
        memset(sl,0,sizeof(sl));
        top=0;
        for(int j=i;j<=n;j++){
            if(sl[a[j]]!=0){
                while(s[top]!=a[j]){
					sl[s[top]]=0;
					top--;
				}
            }
            else{
                s[++top]=a[j];
                sl[a[j]]=1;
            }
        }
        for(int j=1;j<=m;j++){
            if(sl[j]!=0) zs[j]++;
        }
    }
    for(int i=1;i<=m;i++) cout<<zs[i]<<' ';
    fclose(stdin);
    fclose(stdout);
    return 0;
}
