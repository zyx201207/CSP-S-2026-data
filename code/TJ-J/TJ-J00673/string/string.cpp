#include<bits/stdc++.h>
using namespace std;
bool hw(string s){
	string s1;
	for(long long i=s.size()-1;i>=0;i--){
		s1+=s[i];
	}
	if(s==s1) return true;
	else return false;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,t,sum=0;
	string s,s1;
	scanf("%ld",&n);
	for(long long i=0;i<n;i++){
		scanf("%ld",&t);
		cin>>s1;
		for(long long j=0;j<t;j++){
			s+=s1;
		}
	}
	long long len=s.size(),mid1,mid2;
	if(hw(s)){
		cout<<0;
		return 0;
	}else{
		if(len%2==1){
			mid1=len/2;
			mid2=mid1;
		}else{
			mid2=len/2;
			mid1=mid2-1;
			if(s[mid2]!=s[mid1]){
				sum++;	
			}
		}
	}
	string s2,s3;
	for(long long i=0,j=len-1;i<mid1,j>mid2;i++,j--){
		s2+=s[i];s3+=s[j];
	}
	
	for(long long i=0;i<s2.size();i++){
		if(s2[i]!=s3[i]) sum++;
	}
	cout<<sum;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
