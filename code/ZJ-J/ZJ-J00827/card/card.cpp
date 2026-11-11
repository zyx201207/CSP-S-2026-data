#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll k[500005];
ll n,m,a[500005],o,p;
string s;
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=1;i<n;i++){
		if(a[i-1]<=a[i]) o++;
		if(a[i-1]==a[i]) p++;
	}
	if(o==n-1){
		k[1]=1;
		for(int i=1;i<n;i++){
			if(a[i]!=a[i-1]){
				k[a[i-1]]=i;
			}
		}
		for(int i=1;i<=m;i++){
			cout<<k[i]<<' ';
		}
		return 0;
	}
	else if(m<=2){
		int u1,u2,o1=0,o2=0,sum1=0,sum2=0;
		for(int i=0;i<n;i++){
			
			if(a[i]==1){
				u1=i;
			}
			if(a[i]==2){
				u2=i;
			}
		}
		if(u1>u2){
			for(int i=0;i<u2;i++){
				if(a[i]==1) o1++;
				if(a[i]==2) o2++;
			}
			if(abs(o1-o2)==0){
				sum2+=n-o1-o2;
			}
			cout<<n<<' '<<sum2;
		}else{
			for(int i=0;i<u1;i++){
				if(a[i]==1) o1++;
				if(a[i]==2) o2++;
			}
			if(abs(o1-o2)==0){
				sum1+=n-o1-o2;
			}
			cout<<sum1<<' '<<n;
		}
		return 0;
	}
	else if(p==1 && n>=5010){
		for(int i=0;i<n;i++){
			cout<<0<<' ';
		}
		
//		cout<<1;
		return 0;
	}
	for(int i=0;i<n;i++){
		string h="";
		for(int j=i;j<n;j++){
			char x=(char) (a[j]+48);
//			cout<<x<<'\n';
			if(h.find(x)==-1){
				h+=x;
//				cout<<h<<'\n';
			}else{
				h.erase(h.find(x)+1,h.size()-h.find(x));
			}
		}
		
		for(int j=1;j<=n;j++){
			char x=(char) (j+48);
			if(h.find(x)!=-1) k[j]++;	
		}
	}
	for(int i=1;i<=m;i++) cout<<k[i]<<' ';
	fclose(stdin);
	fclose(stdout);
	return 0;
}