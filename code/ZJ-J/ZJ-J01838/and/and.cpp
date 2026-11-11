#include<bits/stdc++.h>
using namespace std;
string t_t_b(int x){
	stack<int> a;
	while(x){
		a.push(x%2);
		x/=2;
	}
	int z=30-a.size();
	string s="";
	for(int i=1;i<=z;i++){
		s+='0';
	}
	while(!a.empty()){
		s+=(a.top()+'0');
		a.pop();
	}
	return s;
}
int n,m;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	vector<int> a(n+1,0);
	vector<string> s(n+1);
	vector<int> site(31,0);
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s[i]=t_t_b(a[i]);
		for(int j=0;j<30;j++){
			if(s[i][j]=='1'){
				site[j]++;
			}
		}
	}
	int siteM=31,nn;
	for(int i=0;i<30;i++){
		if(site[i]>=m){
			siteM=i;
			nn=site[i];
			break;
		}
	}
	for(int i=siteM+1;i<30;i++){
		vector<int> b(nn+1,0);
		vector<string> s_(nn+1);
		vector<int> site_(31,0);
		int se=1;
		for(int j=1;j<=n;j++){
			if(s[j][siteM]=='1'){
				b[se]=a[j];
				s_[se]=t_t_b(a[j]);
				se++;
				for(int k=0;k<30;k++){
					if(s_[se-1][k]=='1'){
						site_[k]++;
					}
				}
			}
		}
		if(nn==m){
			long long ans=0;
			for(int j=0;j<30;j++){
				if(site_[j]>=m){
					ans+=pow(2,30-j-1);
				}
			}
			cout<<ans;
			return 0;
		}
		bool p=true;
		n=nn;
		for(int j=siteM+1;j<30;j++){
			if(site_[j]>=m){
				siteM=j;
				nn=site_[j];
				p=false;
				break;
			}
		}
		if(p||i==29){
			long long ans=0;
			for(int j=0;j<30;j++){
				if(site_[j]>=m){
					ans+=pow(2,30-j-1);
				}
			}
			cout<<ans;
			return 0;
		}
		s.swap(s_);
		a.swap(b);
	}
	return 0;
}
