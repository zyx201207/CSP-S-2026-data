#include<bits/stdc++.h>
using namespace std;
#define ll long long
int x,t;
bool Is(vector<int> x,int n){
	for(int i=1;i<n-1;i++){
		if(x[i+1]-x[i]!=x[i]-x[i-1]){
			return false;
		}
	}
	return true;
}
bool Is2(vector<int> x,int n,int d){
	if(x[0]-x[n-1]<2*d){
		return 1;
	}
	return 0;
}
int pd(vector<int> x,int nb,int d){
	int n=nb;
	int sl=0;
	int k=0;
	for(int i=n-1;i>0;i--){
		if(x[i]-x[i-1]>d){
			k++;
		}
	}
	n-=k;
	if(Is(x,n)){
		if(x[1]-x[0]>d or n%2==1){
			return 0;
		}
		return n-3;
	}
	if(Is2(x,n,d)){
		return n;
	}
	for(int i=0;i<n;i++){
		for(int j=i+3;j<n;j+=2){
			if(x[i]-x[j]>d){
				for(int k=i;k<j;k++){
					if(x[k]==(x[j]-x[i])/(j-i)){
						sl++;
					}
				}
			}
		}
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	cin>>x>>t;
	if(x!=0){
		string s="migrate";
		s+=('0'+x/10);
		s+=('0'+x%10);
		s+=".in";
		char str[s.size()];
		for(int i=0;i<s.size();i++){
			str[i]=s[i];
		}
		freopen(str,"r",stdin);
	} 
	for(int i=0;i<t;i++){
		int n,d;
		cin>>n>>d;
		vector<int> x;
		for(int j=0;j<n;j++){
			int k;
			cin>>k;
			x.push_back(k);
		}
		int sl=pd(x,n,d);
		cout<<sl<<endl;
	}
	return 0;
} 
