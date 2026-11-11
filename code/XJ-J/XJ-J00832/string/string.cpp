#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	string a;
	for(long long i=1;i<=n;i++){
		int x;
		cin>>x;
		string y;
		cin>>y;
		for(int j=0;j<x;j++){
			a+=y;
		}
	}
	long long sum,sum1=0,sum2=0;
	string b=a,w=a;
	reverse(b.begin(),b.end());
	if(a==b){
		cout<<0;
		return 0;
	}else{
		string aq=a.substr(0,a.size()/2),ah=a.substr(a.size()/2,a.size()-a.size()/2);
		for(long long i=0;i<w.size()/2;i++){
			if(b[i]!=aq[i]){
				sum1++;
			}
		}
		for(long long i=w.size()/2;i<w.size();i++){
			if(b[i]!=ah[i]){
				sum2++;
			}
		}
		sum=min(sum1,sum2);
	}
	cout<<sum;
	return 0;
}


