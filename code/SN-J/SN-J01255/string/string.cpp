#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+7;
int a[N];
int n;
int check(string s){
	int ans=0;
	if(s.size()%2==1){		
		int mid=(s.size()-1)/2;
		int l,r;
		for(int i=1;i<=mid;i++){
			l=mid-i;
			r=mid+i;
			if(l<0)break;
			if(r>s.size()-1)break;
			if(s[l]!=s[r])ans++;
		}
		return ans;
	}
	else {
		for(int i=0;i<s.size();i++){
			if(s[i]!=s[s.size()-i])ans++;
		}
		return ans/2;
	}
}
void BB(){
	for(int i=1;i<=n;i++){
		
	}
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	string s;
	cin>>n;
	ll pl;
	for(int i=1;i<=n;i++){
		string y;
		cin>>a[i]>>y;
		if(a[i]<=N){			
			for(int j=1;j<=a[i];j++){
				s+=y;
			}
		}
		else pl+=a[i];
	}
	if(pl>=10*N)BB();
	cout<<check(s);
	return 0;
	
} 
