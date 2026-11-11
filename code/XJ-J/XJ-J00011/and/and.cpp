#include<bits/stdc++.h>
using namespace std;
struct lsp{
	int ab;
	int num;
};
bool cmp(lsp x,lsp y){
	return x.num>y.num;
}	
int a[1000010];
lsp b[1000010];
string s;
int main(){
	freopen("and.in",r,stdin);
	freopen("and.out",w,stdout);
	int n,m,t;
	cin>>n>>m;

	for(int i = 1;i<=n;i++){
		cin>>a[i];
	}
	for(int i = 1;i<=n;i++){
		int x = a[i];
		s = " ";
		while(x!=0){
			s+=x%2;
			x/=2;
		}
		reverse(s.begin(),s.end());
		for(int j = 0;j<s.size();j++){
			if(s[j] == 1){
				t++;
			}
		}
		b[i].num = t;
		b[i].ab = a[i];
	}
	sort(b+1,b+n+1,cmp);
	int ans = b[1].ab;
	for(int i = 2;i<=m;i++){
		ans = max(ans,ans&b[i].ab);
		//cout<<ans<<endl;
	}
	cout<<ans;
	return 0;
}

