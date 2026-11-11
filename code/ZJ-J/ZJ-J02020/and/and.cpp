#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+5;
long long k[N];
long long f(long long x,long long y){
	string n,m;
	int i=0;
	while(x>0){
		if(x%2==0) n[i]=char(0);
		else n[i]=char(1);
		x/=2;
	}
	while(y>0){
		if(y%2==0) m[i]=char(0);
		else m[i]=char(1);
		y/=2;
	}
	string a;
	long long len=n.size(),len2=m.size();
	for(int i=0;i<=min(len,len2);i++){
		if(len>len2){
			if(n[i+(len-len2)]==char(1)&&m[i]==char(1)){
				a[i]=char(1);
			}else{
				a[i]=char(0);
			}
		}else{
			if(m[i+(len2-len)]==char(1)&&n[i]==char(1)){
				a[i]=char(1);
			}else{
				a[i]=char(0);
			}
		}
	}
	long long ans=0;
	int sum=0;
	for(int i=a.size()-1;i>=0;i--){
		if(a[i]==char(1)){
			ans+=pow(2,sum);
		}
		sum++;
	}
	return ans;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>k[i];
	}
	if(m==1){
		long long x=-1;
		for(int i=0;i<n;i++){
			if(k[i]>=x) x=k[i];
		}
		cout<<x;
		return 0;
	}else if(m==2){
		long long res=-1;
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				//cout<<f(k[i],k[j])<<endl;
				if(f(k[i],k[j])>=res){
					res=f(k[i],k[j]);
				}
			}
		}
		cout<<res;
		return 0;
	}
	return 0;
}
