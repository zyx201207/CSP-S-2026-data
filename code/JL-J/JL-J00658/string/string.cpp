#include<bits/stdc++.h>
using namespace std;
const long long N=2e5+10;
long long n,a[N],middle,counts;
char c[N];
string s1;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i]>>c[i];
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<a[i];j++){
			s1+=c[i];
		}
	}
	middle=(s1.size()+1)/2;
	for(int i=0;i<middle-1;i++){
		if(s1[i]!=s1[i+middle+1]){
			counts++;
		}
	}
	cout<<counts;
}
