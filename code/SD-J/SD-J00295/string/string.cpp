#include<bits/stdc++.h>
using namespace std;
long long cnt,mid,ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string s;
	int n;cin>>n;
	for(int i=1;i<=n;i++){
		int x;cin>>x;
		char c;cin>>c;
		cnt+=x;
		for(int j=1;j<=x;j++){
			s+=c;
		}
	}
	//cout<<s<<endl;
	if(cnt&1){
		mid=cnt/2+1;
		ans=cnt-mid;
		//cout<<cnt<<' '<<mid<<' '<<ans<<endl;
		for(long long i=1;i<mid;i++){
			if(s[mid-1-i]==s[mid-1+i]){
				//cout<<i<<' ';
				ans--;
			}
		}
	}else{
		mid=cnt/2;
		ans=cnt-mid;
		if(s[mid]==s[mid-1]) ans--; 
		for(long long i=1;i<mid;i++){
			if(s[mid-2-i]==s[mid+i]) ans--;
		}
	}
	cout<<ans;
	return 0;
}
