#include<bits/stdc++.h>
using namespace std;
long long n,a[200002],num,wrong;
char s[1000000001],c[200002];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i]>>c[i];
		num+=a[i];
		for(int j=num-a[i];j<num;j++){
			s[j]=c[i];
		}
	}long long head,last;
	if(num%2==1){
		head=(num-1)/2-1;
		last=(num-1)/2+1;
		for(int i=0;i<=head;i++){
			if(s[head]!=s[last]){
				wrong++;
			}
		}cout<<wrong;
		return 0;
	}if(num%2==0){
		head=num/2-1;
		last=num/2;
		for(int i=0;i<=head;i++){
			if(s[head]!=s[last]){
				wrong++;
			}
		}cout<<wrong;
		return 0;
	}
	return 0;
}
