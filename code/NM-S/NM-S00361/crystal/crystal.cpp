#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,m,a[500005],ans=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    while(m){
        for(int i=1;i<=n;i++){
            if((m>=a[i+1]-a[i])){
                m=m-i*(a[i+1]-a[i]);
                ans=i;
                continue;
            }
            else{
                break;
            }
        }
    }
    cout<<ans+1<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
