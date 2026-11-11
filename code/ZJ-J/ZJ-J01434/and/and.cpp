#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int a,b;
	cin>>a>>b;
	vector<long long>num(a+1,0);
	long long maxx=-1;
	for(int i=0;i<a;i++){
		long long x;
		cin>>x;
		num[i]=x;
		maxx=max(x,maxx);
	}
	long long tw=1;
	while(tw<=maxx){
		tw=tw*2;
	}
	long long ans=0;
	
	while(tw!=0){
		vector<long long>ne;
		tw/=2;
		long long ji=0;
		for(int i=0;i<num.size();i++){
			
			if((num[i]&tw)!=0){
				ji++;
				ne.push_back(num[i]);
			}
		}
		if(ji>=b){
			ans+=tw;
			num.erase(num.begin(),num.end());
			for(int i=0;i<ne.size();i++){
				
				
				num.push_back(ne[i]);
			}
			
		}
	}
	cout<<ans<<endl;
	
}
