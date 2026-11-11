#include<bits/stdc++.h>
using namespace std;
const int MAXN=2e5+5;
struct stu{
	long long x;
	char c;
};
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	long long x;char c;string s;
	vector<stu> v;
	for(int i=1;i<=n;i++){
		cin>>x>>c;
		//for(int j=1;j<=x;j++)s=s+c;
		v.push_back({x,c});
	}
	for(int i=0;i<v.size();i++){
		//cout<<v.size()<<endl;
		if(i+1<v.size()){
			if(v[i].c==v[i+1].c){
				v[i].x+=v[i+1].x;
				v.erase(v.begin()+i+1);
				i--;
				//cout<<v.size()<<endl;
				//break;
			}
		}
	}
	int m=v.size();
	//cout<<m<<endl;
	for(int i=0;i<=m/2;i++){
		if(v[i].c==v[v.size()-i-1].c){
			if(v[i].x==v[v.size()-i-1].x){
				if(!v.empty())v.erase(v.begin()+i);
				if(!v.empty())v.erase(v.begin()+(v.size()-1-i));
				//i--;
			}else{
				if(v[i].x>v[v.size()-i-1].x){
					v[i].x -= v[v.size()-i-1].x;
					if(!v.empty())v.erase(v.begin()+(v.size()-1-i));
				}else{
					v[v.size()-i-1].x -= v[i].x;
					if(!v.empty())v.erase(v.begin()+i);
				}
			}
		}
	}/*
	int m=s.size();
	for(int i=0;i<s.size()/2;i++){
		if(s[i]==s[s.size()-1-i]){
			s.erase(s.begin()+(s.size()-1-i));
			s.erase(s.begin()+i);
			i--;
		}
	}*/
	long long sum=0;
	for(int i=0;i<v.size();i++){
		sum+=v[i].x;
	}
	sum/=2;
	cout<<sum;
	return 0;
}
