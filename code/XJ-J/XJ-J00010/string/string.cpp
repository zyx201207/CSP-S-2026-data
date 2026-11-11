#include<bits/stdc++.h>
using namespace std;
long long int a[10000000];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long int n;
	cin>>n;
	string s="";
	
	for(long long int i=0;i<n;i++){
		char f;
		cin>>a[i];
		cin>>f;
		for(long long int j=0;j<a[i];j++){
			if(a[i]-j>=10){
				j+=9;
				s+=f;
				s+=f;
				s+=f;
				s+=f;
				s+=f;
				s+=f;
				s+=f;
				s+=f;
				s+=f;
			}
			s+=f;
		}
		
	}
	
	bool p=1;
	
	
	for(long long int j=0;j<s.size()/2;j++){
			if(!(s[j]==s[s.size()-j-1])){
				p=0;
			}
	}
	if(p==1){
		cout<<0;
		return 0;
	}
	long long int sum=0,z=0;
	for(long long int j=0;j<s.size()/2;j++){
		if(!(s[j]==s[s.size()-j-1])){
			if(a[j]==a[j+1]&&a[j]%10==0){
				a[j+1]=a[j];
				sum+=a[j]/10+1;
				j+=a[j]/10;
				z+=a[j]/10;
			}else{
				s[s.size()-j-1]=s[j];
					sum++;
					z++;
				if(s[j]==s[j+1]){
					long long int o=0;
					for(long long int i=j;i<s.size()/2;i++){
						if(s[i]==s[i+1]){
							o++;
						}if(s[i]==s[i*10]){
							o+=i*9;
							i*=10;
							if(s[i]==s[i*100]){
								o+=i*99;
								i*=100;
								if(s[i]==s[i*1000]){
									o+=i*999;
									i*=1000;
								}
							}
						}
					}
					sum+=o;
					j+=o;
					z+=o;
				}
			}
				
		}
		
	}
	cout<<sum;
	return 0;
}