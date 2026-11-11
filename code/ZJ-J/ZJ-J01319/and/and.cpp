#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
int n,m;
int a[N],bt[N][35];
vector <int> num;
string get_two(int val){
	string tmp="",ans="";
	while(val!=0){
		tmp+=val%2+'0';
		val/=2;
	}
	for(int i=tmp.size();i<=30;i++)
		ans+="0";
	for(int i=tmp.size()-1;i>=0;i--)
		ans+=tmp[i];
	return ans;
}
void query(int idx){
	vector <int> tmp;
	tmp.clear();
	if(num.size()==0){
		for(int i=1;i<=n;i++){
			if(bt[i][idx]==1)
				tmp.push_back(i);
		}		
	}else{
		for(int i=0;i<num.size();i++){
			if(bt[num[i]][idx]==1)
				tmp.push_back(num[i]);
		}		
	}
	if(tmp.size()>=m)
		num=tmp;
	return ;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++)
		cin >> a[i];
	for(int i=1;i<=n;i++){
		string two=get_two(a[i]);
		two=" "+two;
		for(int j=1;j<=two.size()-1;j++)
			bt[i][j]=two[j]-'0';
	}
	for(int i=1;i<=31;i++)
		query(i);
	if(num.size()<1){
		cout<<'0'<<'\n';
		return 0;
	}
	int ans=a[num[0]];
	for(int i=1;i<num.size();i++){
		ans=(ans & a[num[i]]);
	}
	cout<<ans<<'\n';
}