#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e6+5;
ll m,n,a[N];
__int128 nowc,b[N],s[N],mid,minn;
__int128 cnt=1,ans=-0x3f3f3f3f;
void write(__int128 x){
	if(x<0){
		cout<<"-";
		x=-x;
	}
	if(x>9){
		write(x/10);
	}
	cout<<(char)(x%10+'0');
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
    	
	}
	sort(a+1,a+1+n);//ji ou??
	minn=a[1];
	for(int i=1;i<=n;i++){
		a[i]+=abs(minn);
	}
	for(int i=1;i<=n;i++){
		s[i]=a[i]+s[i-1];
	}
//	for(int i=1;i<=n;i++){
//		cout<<s[i]<<" ";
//	}
//	cout<<'\n';
	for(__int128 i=1;i<=n;i++){
		if(a[i]==a[i-1]){
			cnt++;
		}
		else{
			cnt=1;
		}
		nowc=abs(s[i]-a[i]*i);
//		cout<<nowc<<'\n'; 
		if(m>=nowc){
			ans=max(ans,i);
		}
		else if(n<=5e3&&cnt!=1){
			for(__int128 j=1;j<=i;j++){
				nowc=abs(s[i]-s[j-1]-a[i]*(i-j+1));
				if((__int128)m>=nowc){
					ans=max(ans,i-j+1);
				}
			}
		}
		ans=max(ans,cnt);
	}
	write(ans);
	return 0;
}
