#include<iostream>
using namespace std;
int n;
long long a[400001];
char c[400001];
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=0;i<n;i++){
		cin>>a[i];
		cin>>c[i];
		for(long long j=0;j<a[i];j++){
			s+=c[i];
		}
	}
	int sum=0,l=s.size();
	for(long long i=0;i<l;i++){
		for(long long j=l;j>0;j--){
			if(s[i]!=s[j]&&i+j==l-1&&i<=j){
				sum++;
				i++;
				j++;
			}
		}
	}
	cout<<sum;
	return 0;
}
