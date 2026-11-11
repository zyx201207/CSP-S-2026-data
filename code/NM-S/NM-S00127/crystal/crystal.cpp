#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=500005;
ll m;
int n;
int a[maxn];
int main(){
    freopen("ctystal.in","r",stdin);
    freopen("ctystal.out","w",stdout);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    int c[maxn]={0};
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    for(int i=2;i<=n;i++){
        c[i-1]=a[i]-a[i-1];
    }
    sort(c+1,c+n);
    bool dengcha=0;
    int ans=1;
    if(c[1]==c[n-1])dengcha=1;
    if(dengcha){
        int ch=c[1];
        if(n*(n-1)*ch/2.0<=m)cout<<n;
        else{
            for(int i=1;i<n;i++){
                m-=i*ch;
                if(m<=0){
                    ans=max(i,1);
                    cout<<ans<<"\n";
                    return 0;
                }
            }
        }
    }
    else{
    	int c[maxn];
		int fr[maxn]={0};
		ll Ans=1;
   		for(int i=2;i<=n;i++){
        	c[i-1]=a[i]-a[i-1];
        	fr[i-1]=fr[i-2]+c[i-1];//fr[i]-fr[i-1]=c[i]
    	}
    	//for(int i=1;i<=n;i++)cout<<c[i]<<" "<<fr[i]<<"\n";
    	int ans[maxn]={0};
    	for(int i=1;i<=n;i++){
			ll m1=m;
    		ans[i]++;
    		if(i>=2){
    			for(int j=i-1;j>=0;j--){
    				if(m1-abs(fr[i]-fr[j])>=0){
    					m1-=abs(fr[i]-fr[j]);
    					//cout<<"m1="<<m1<<"\n";
    					/*cout<<"(fr[i]-fr[j])="<<(fr[i]-fr[j])<<"\n";
    					cout<<fr[i]<<" "<<fr[j]<<"\n";*/
    					ans[i]++;
					}
					else break;
				}
			}
			//cout<<ans[i]<<"\n";
			Ans=max(Ans,(ll)ans[i]);
			//cout<<"----------------------"<<"\n";
		}
		cout<<Ans;
	}
	return 0;
}
