#include<bits/stdc++.h>
using namespace std;
struct a{
	long long num;
	char c;
}f[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin>>n;
	long long sum=0;
	for(long long i=0;i<n;i++){
		long long ss;
		char cc;
		cin>>ss;
		f[i].num=ss;
		cin>>cc;
		f[i].c=cc;
	}
	
	for(long long j=n-1,i=0;i<n;){
		if(f[i].c!=f[n-i-1].c){
			sum+=min(f[i].num,f[j].num);
			if(f[i].num>f[j].num){
				f[i].num-=f[j].num;
				j--;
			}
			if(f[i].num<f[j].num){
				f[j].num-=f[i].num;
				i++;
			}
			if(f[i].num==f[j].num){
				i++;
				j--;
			}
		}else{
			if(f[i].num>f[j].num){
				f[i].num-=f[j].num;
				j--;
			}
			if(f[i].num<f[j].num){
				f[j].num-=f[i].num;
				i++;
			}
			if(f[i].num==f[j].num){
				f[j].num=0;
				f[i].num=0;
				i++;
				j--;
			}
		}
	}
	
	cout<<sum;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
