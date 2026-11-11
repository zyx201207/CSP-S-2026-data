#include <bits/stdc++.h>
using namespace std;
string a;
const int N=2e5+10;
long long n,m[N],sum,j;
char c[N];
bool f;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>m[i]>>c[i];
	}
	for(int i=1;i<n;i++){
		if(c[i]!=c[i+1]){
			f=1;
		}
	}
	if(!f){
		cout<<0;
		return 0;
	}
	j=n;
	for(int i=1;i<j;){
		if(c[i]!=c[j]){
			sum+=min(m[i],m[j]);
			if(m[i]>m[j]){
				m[i]-=m[j];
				m[j]=0;
				j--;
			}else{
				if(m[i]<m[j]){
					m[j]-=m[i];
					m[i]=0;
					i++;	
				}else{
					m[i]=0;
					m[j]=0;
					i++;
					j--;
				}
			}
		}else{
			if(m[i]>m[j]){
				m[i]-=m[j];
				m[j]=0;
				j--;
			}else{
				if(m[i]<m[j]){
					m[j]-=m[i];
					m[i]=0;
					i++;	
				}else{
					m[i]=0;
					m[j]=0;
					i++;
					j--;
				}
			}
		}
	} 
	cout<<sum;
	return 0;
}