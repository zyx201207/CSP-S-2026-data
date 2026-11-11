#include<bits/stdc++.h>
using namespace std;
/*====================*/
using lnt=long long;
using pnt=pair<long long,pair<char,char> >;
/*====================*/
char arr[200500];
lnt len[200500];
set<pnt> s;
vector<pnt> v;
/*====================*/
bool Cmp(pnt a,pnt b){
	return a.first<b.first;
}
/*====================*/
void Solve(){
	lnt n; cin>>n;
	lnt m=0;
	for(int i=1;i<=n;i++){
		lnt x; cin>>x;
		char c; cin>>c;
		arr[i]=c;
		len[i]=x;
	}
	for(int i=1;i<=n;i++) m+=len[i];
	/*====================*/
	lnt lft=1;
	for(int i=1;i<=n;i++){
		v.push_back({lft,{arr[i],'$'}});
		lft+=len[i];
		v.push_back({m-lft+2,{'$',arr[i]}});
	}
	sort(v.begin(),v.end(),Cmp);
	for(int i=0;i<n*2;){
		if(i+1==n*2){
			s.insert(v[i]);
			i++;
		}
		else{
			if(v[i].first==v[i+1].first){
				lnt x=v[i].first;
				char y,z;
				if(v[i].second.first=='$'){
					y=v[i+1].second.first;
					z=v[i].second.second;
				}
				else{
					y=v[i].second.first;
					z=v[i+1].second.second;
				}
				s.insert({x,{y,z}});
				i+=2;
			}
			else{
				s.insert(v[i]);
				i++;
			}
		}
	}
	s.insert({m+1,{'$','$'}});
	/*====================*/
	lnt ans=0,lst=0;
	char my_clr_1='$',my_clr_2='$'; 
	for(auto i:s){
		lnt x=i.first;
		char y=i.second.first;
		char z=i.second.second;
		if(my_clr_1!=my_clr_2){
			ans+=x-lst;
		}
		lst=x;
		if(y!='$') my_clr_1=y;
		if(z!='$') my_clr_2=z;
	}
	cout<<ans/2<<'\n';
	return;
}
/*====================*/
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int T=1; //cin>>T;
	while(T--) Solve();
	return 0;
}
