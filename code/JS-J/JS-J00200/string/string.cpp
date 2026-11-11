#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;

const int N=1e6+1;
int a[N];
char b[N];
int c[N]={0};
bool ed=false;
ll num=0;
ll num1=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	string s;
	for(int i=0;i<n;i++){
		cin>>a[i]>>b[i];
		num+=a[i];
	}
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(b[i]!=b[j]){
				ed=true;
			}
		}
	}
	if(ed==false){
		cout<<"0";
		return 0;
	}else{
		cout<<num/2;
	}
	
	return 0;
}
