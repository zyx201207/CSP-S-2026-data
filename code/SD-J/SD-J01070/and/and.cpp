#include <bits/stdc++.h>
using namespace std;

long long n,m;
long long ans;

string er(int x){
	string ss;
	while(x!=0){
		if(x%2==0)
			ss+='0';
		else
			ss+='1';
		x/=2;
	}
	for(int i=0;i<ss.length()/2;i++)
		swap(ss[i],ss[ss.length()-1-i]);
	return ss;
}
int yu(int a,int b){
	string ssa,ssb,ssc;
	ssa=er(a),ssb=er(b);
	for(int i=ssa.length()-1;i>=0;i--){
		ssc+=min(ssa[i],ssb[i]);
	}
	int an=0;
	for(int i=0;i<ssc.length();i++)
		an+=pow(2,i)*(ssc[i]-'0');
	return an;
}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	long long a[n],l[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
		int idx=0;
		while(1){
			if(a[i]<pow(2,idx)){
				l[i]=idx;
				break;
			}
			idx++;
		}
	}
	while(1){
		int mx=l[0],ms=0;
		for(int i=0;i<n;i++){
			if(l[i]==mx)
				ms++;
			else if(l[i]>mx)
				mx=l[i],ms=1;
		}
		if(ms>=m)
			break;
		else{
			for(int i=0;i<n;i++){
				if(l[i]==mx){
					a[i]-=pow(2,l[i]-1);
					int idx=0;
					while(1){
						if(a[i]<pow(2,idx)){
							l[i]=idx;
							break;
						}
					idx++;
					}
				}
			}
		}
	}
	sort(a,a+n);
	ans=a[n-1];
	for(int i=1;i<m;i++)
		ans=yu(ans,a[n-1-i]);
	cout<<ans;
	return 0;
}
