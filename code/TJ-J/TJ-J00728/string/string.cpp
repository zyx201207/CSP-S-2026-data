#include<bits/stdc++.h>;
using namespace std;
long long n,a[9000010],m;
string s;
char c[9000010];
int sum=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	if(n==1)	cout<<0;
	else{
		for(long long i=1;i<=n;i++){
			cin>>a[i]>>c[i];
		}	
		for(long long i=1;i<=n;i++){
			m+=a[i];
		}
		for(long long i=1;i<=n;i++){
			for(int j=0;j<a[i];j++){
				s+=c[i];
			}
		} 
		if(m%2==0){
			int cnt=0;
			for(long long i=0;i<s.size()/2;i++){
				if(s[i]!=s[s.size()-i-1])	cnt++;
			}	
			cout<<cnt;
		}
		else{
			long long cnt=0;
			for(long long i=0;i<s.size()/2;i++){
				if(s[i]!=s[s.size()-i-1]){
					cnt++;	
				}	
			}	
			cout<<cnt;
		}		
	}
	fclose(stdin);
	fclose(stdout);
	return 0; 
} 
