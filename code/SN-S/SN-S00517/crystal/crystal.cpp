#include<bits/stdc++.h>
using namespace std;
int n,ans,fl,cnt,s;
bool flag=true;
long long m;
long long a[200005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	s=m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	fl=a[2]-a[1];
	for(int i=2;i<=n;i++){
		if(a[i]-a[i-1]!=fl){
			flag=false;
			break;
		}
	}
	if(flag==true){
		int cha=a[2]-a[1];
    	int d=m/cha;
	    int h=min(d,n);
	    for(int i=1;i<=h;i++){
		    cnt+=i*cha;
		    ans++;
		    if(cnt>=m){
			    break;
		    }
	    }
	    cout<<ans;
	}else{
			sort(a+1,a+1+n);
			for(int i=1;i<=n;i++){
				cnt=0;
				m=s;
				for(int j=i;j>=1;j--){
					m-=a[i]-a[j];
					if(m<=0){
						break;
					}else{
						cnt++;
					}	
				}
				if(m<0){
					cnt--;
				}else{
					cnt++;
				}
				ans=max(ans,cnt);
			}
			cout<<ans;
		
	}

	return 0;
} 
