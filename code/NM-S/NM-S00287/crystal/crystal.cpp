#include<bits/stdc++.h>
using namespace std;
int n;
const long long N=200e6;
long long num=0,ans=0;
long long m,a[N];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    long long t=1;
    while(m>0){
    	long long h=0;
    	if((a[t+1]-a[t])*t<=m){
    		h=(a[t+1]-a[t]);
		}
		else break;
        m-=h;
        for(int i=1;i<=t;i++){
			a[i]+=h;
			}
			t++;
		for(int i=1;i<=n;i++){
			if(a[i]==a[i+1]){
                    num++;
			}
			else{
				if(num>=ans){
					ans=num;
					num=1;
				}
				else num=1;
			}
		}
		}
	cout<<ans<<endl;
	cout<<N;
    return 0;
}

