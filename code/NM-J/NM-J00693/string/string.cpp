#include<bits/stdc++.h> 
using namespace std;
string a[100001];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin>>n;
	int he=0;
	for(long long i=1;i<=n;i++){
		long long j;
		cin>>j;
		char k;
		cin>>k;
		for(int q=1;q<=j;q++){
			a[he+q]=k;
		}he+=j;
	}long long sum=0;
	for(int i=1;i<=he/2;i++){
		if(a[i]!=a[he-i+1]){
			sum++;
		}
	}cout<<sum;
	return 0;
	fclose(stdin);
	fclose(stdout);
}
