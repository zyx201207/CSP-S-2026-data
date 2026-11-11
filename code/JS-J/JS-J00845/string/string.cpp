#include<bits/stdc++.h>
using namespace std;
long long cnt[200005];
char c[200005];
int main(){
	//freopen("string.in","r",stdin);
	//freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>cnt[i]>>c[i];
	}
	long long a=1,b=n;
	long long l=cnt[a],r=cnt[b];
	unsigned long long sum=0;
	while(a<b){
		if(c[a]!=c[b]){
			if(l>r){
				sum+=r;
				l-=r;
				b-=1;
				r=cnt[b];
			}
			if(l<r){
				sum+=l;
				r-=l;
				a+=1;
				l=cnt[a];
			}
			if(l==r){
				sum+=l;
				a+=1;
				b-=1;
				l=cnt[a];
				r=cnt[b];
			}
		}
		else if(l!=r){
			if(l>r){
				l-=r;
				b-=1;
				r=cnt[b];
			}
			if(l<r){
				r-=l;
				a+=1;
				l=cnt[a];
			}
		}
		else {
			a+=1;
			b-=1;
			l=cnt[a];
			r=cnt[b];
		}
	}
	cout<<sum;
	//fclose(stdin);
	//fclose(stdout);
	return 0;
}
	
