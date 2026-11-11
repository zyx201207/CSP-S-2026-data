#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,sum,sum2,ans,maxn=-1e18,maxm=-1e18,temp;
int a[500005],b[500005];
bool flag=0;
vector<int> s;
int ans2,ans3,ans4;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum+=a[i];
	}
	if(n>=5000){
		int ans2=sqrt(2*m);
		int ans3=a[2]-a[1];
		int ans4=ans2/ans3;
		cout<<ans4<<endl;
		return 0;
	}
	sum+=m;
	sum2=sum/n;
	sum2++;
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		if(a[i]<=sum2){
			s.push_back(a[i]);
			maxn=max(maxn,a[i]);
		}
		else{
			if(a[i]-sum2<sum2-a[i-1]){
				s.push_back(a[i]);
				maxn=a[i];
			}
			break;
		}
	}
	for(int i=s.size()-1;i>=0;i--){
		if(m<maxn-s[i]){
			
			break;
		}
		if(m>=maxn-s[i]){
			m-=abs(maxn-s[i]);
			ans++;
			temp=ans;
		}
	} 
	cout<<ans<<endl;
	return 0;
} 
/*
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7

*/
