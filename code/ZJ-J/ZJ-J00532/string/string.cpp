#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+10;
int n,cnt;
int x[N];
char y[N];
int q[N][35],qq[N];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
    	cin>>x[i]>>y[i];
    	qq[i]=qq[i-1]+x[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=26;j++){
			q[i][j]=q[i-1][j];
			if(j==y[i]-'a'+1){
				q[i][j]+=x[i];
			}
		}
	}
	for(int i=1;i<=n;i++){
		int s=qq[i-1]+1,w=qq[i];
		s=qq[n]-s+1;
		w=qq[n]-w+1;
		if(s>w)swap(s,w);
		int l=1,r=n,ans=0;
		while(l<=r){
			int mid=(l+r)/2;
			if(qq[mid-1]+1<=s){
				ans=mid;
				l=mid+1;
			}
			else{
				r=mid-1;
			}
		}
		int sum=0;
		l=1;
		r=n;
		while(l<=r){
			int mid=(l+r)/2;
			if(qq[mid]>=w){
				sum=mid;
				r=mid-1;
			}
			else{
				l=mid+1;
			}
		}
		if(ans==sum){
			if(y[ans]==y[i]){
				
			}
			else{
				cnt+=w-s+1;
			}
		}
		else{
			if(y[ans]==y[i]){
				
			}
			else{
				cnt+=qq[ans]-s+1;
			}
//			cout<<y[ans]<<" "<<y[i]<<" "<<cnt<<":";
			ans++;
			if(y[sum]==y[i]){
				
			}
			else{
				cnt+=w-(qq[sum-1]);
			}
//			cout<<y[sum]<<" "<<y[i]<<" "<<cnt<<":";
			sum--;
			if(sum<ans) ;
			else cnt+=qq[sum]-qq[ans-1]-q[sum][y[i]-'a'+1]+q[ans-1][y[i]-'a'+1];
//			cout<<s<<" "<<w<<" "<<ans<<" "<<sum<<" "<<qq[sum]-qq[ans-1]<<" "<<cnt<<"\n";
		}
	}
	cout<<cnt/2;
	return 0;
}
/*
5
1 a
2 b
3 c
4 d 
5 e
*/