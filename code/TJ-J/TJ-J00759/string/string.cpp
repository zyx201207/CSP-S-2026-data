#include <bits/stdc++.h>
using namespace std;
struct a{
	long long num;
	char ans;
}q[1000001];
long long u[1000001];
long long m[1000001];
long long sum=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin>>n;
	string s="";
	for(int i=1;i<=n;i++){
		long long a;
		cin>>a;
		q[i].num=a;
		char b;
		cin>>b;
		q[i].ans=b;
		for(int j=1;j<=a;j++){
			s+=b;
		}
		u[i]=u[i-1]+a;
		m[i]=a+1;
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(q[i].ans==q[j].ans){
				q[i].num+=q[j].num;
				q[j].num+=q[i].num;
				u[i]=u[j];
			}
		}
		
	}
	long long l=0,r=s.size()-1;
	if(s.size()%2==0){
		while(l!=r&&l+1!=r){
			if(s[l]!=s[r]){
				for(int i=1;i<=s.size()/2;i++){
					if(q[i].ans==s[l]){
						if(q[i].num%2==0){
							cout<<u[i]<<' ';
							s[u[i]-1]=s[r];
							sum++;
						}
						else if(q[i].num%2!=0)  sum++;
						break;
					}
				}
			}
			l++;
			r--;
		
		}
	}
	else{
		while(l!=r&&r+1!=l){
			if(s[l]!=s[r]){
				for(int i=s.size();i>=s.size()/2;i--){
					if(q[i].ans==s[r]){
						if(q[i].num%2==0){
							cout<<m[i]<<' ';
							s[m[i]-1]=s[l];
							sum++;
						}
						else if(q[i].num%2!=0)  sum++;
						break;
					}
				}
			}
			l++;
			r--;
		
		}
	}
	cout<<sum;
	return 0;
} 
