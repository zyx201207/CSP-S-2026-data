#include<bits/stdc++.h>
using namespace std;
map < char , long long > mpq,mph;
long long n,t[200100],f,sum,s,k,shq,shh,q;
char a[200100];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>t[i]>>a[i];
		s+=t[i];
	}
	q=0;
	if(s%2==0){
		for(int i=1;i<=n;i++){
			if(f+t[i]>=s/2&&!q){
				shq=s/2-f;
				mpq[a[i]]+=shq;
				shh=f+t[i]-s/2;
				mph[a[i]]+=shh;
				q=1;
			}
			else if(f+t[i]<s/2){
				mpq[a[i]]+=t[i];
			}
				else mph[a[i]]+=t[i];
			f+=t[i];
		}
		for(char i='a';i<='z';i++){
			sum+=abs(mpq[i]-mph[i]);
		}
		cout<<sum/2;
	}
	else{
		k=(s+1)/2;
		for(int i=1;i<=n;i++){
			if(f+t[i]>=k&&!q){
				shq=k-f-1;
				mpq[a[i]]+=shq;
				shh=f+t[i]-k;
				mph[a[i]]+=shh;
				q=1;
			}
			else if(f+t[i]<k){
				mpq[a[i]]+=t[i];
			}
				else mph[a[i]]+=t[i];
			f+=t[i];
		}
		for(char i='a';i<='z';i++){
			sum+=abs(mpq[i]-mph[i]);
		}
		cout<<sum/2;
	}
}

