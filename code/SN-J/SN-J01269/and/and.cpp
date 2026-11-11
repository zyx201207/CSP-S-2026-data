#include<bits/stdc++.h> 
#define int long long
using namespace std;
vector<string>g1,g2;
int n,m;
int bestps=-1;
int pos1[60];
signed lest=0;
bool chosed[60];//已选择2的次幂 
//int layer;//已找到层数
//int intoo[200007]// 已选择数字的次数 
string turns1(int a){
	string s="";
	while(a){
		if(a%2==1){
			s=s+"1"; 
			pos1[signed(s.size())-1]++;
		}
		else s=s+"0";
		a/=2; 
	}
	lest=max(lest,signed(s.size()));
	return s;
}
string turns2(string s){
	for(int i=s.size();i<lest;i++){
		s=s+"0";
	}
	return s;
}
bool check(int ne){
	int totoal=0;
	if(g1.empty()){
		for(string i:g2){
			if(i[ne]=='1')totoal++;
		}
		
	}
	else{
		for(string i:g1){
			if(i[ne]=='1')totoal++;
		}
	}
	return bool(totoal>=m);
}
signed main(){
	freopen("and.in" , "r" , stdin);
	freopen("and.out" , "w" , stdout);
	cin.tie(0);
	cout.tie(0);
	//转化 30*n;
	//最坏30轮查询 900*n O(n)but 2*1e8 
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int a;
		cin>>a;
		g1.push_back(turns1(a));
		
	}
	for(string now: g1){
		g2.push_back(turns2(now));
		//cout<<turns2(now)<<endl;
	}
	g1.clear();
	
	for(int i=0;i<=40;i++){
		if(pos1[i]>=m){
			bestps=i;
		}
	}
	if(bestps==-1){
		cout<<0;
		return 0;
	}
	for(string i:g2){
		if(i[bestps]=='1'){
			g1.push_back(i);
		}
	} 
	g2.clear();
	//回g1 
	chosed[bestps]=1;
	while(1){
		bool found=0;
		for(int i=bestps-1;i>=0;i--){
			if(pos1[i]>=m){
				if(check(i)){
					found=1;
					if(g1.empty()){
						for(string j:g2){
							if(j[i]=='1')g1.push_back(j);
						}
						g2.clear();
					}
					else{
						for(string j:g1){
							if(j[i]=='1')g2.push_back(j);
						}
						g1.clear();
						
					}
					bestps=i;
					chosed[bestps]=1;
					break;
				}
			}
		}
		if(!found)break; 
	}
	int ans=0;
	unsigned long long p2=1;
	for(int i=0;i<=31;i++){
		if(chosed[i])ans+=p2;
		p2*=2;
	}
	cout<<ans;
} 
