#include<bits/stdc++.h>
using namespace std;
struct S{
	long long c;
	char d;
}k[200050];

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long cnt=0;
	int a,n;
	char b;
	cin>>n;
	for(int i=0;i<n;i++){
		scanf("%d %c",&a,&b);
		k[i].c=a;
		k[i].d=b;
	}int j=n-1;
	for(int i=0;i!=j;){
		if(k[i].c<k[j].c){
			if(k[i].d!=k[j].d)cnt+=k[i].c;
			k[j].c-=k[i].c;
			i++;
		}
		else if(k[i].c==k[j].c){
			if(k[i].d!=k[j].d)cnt+=k[i].c;
			k[j].c-=k[i].c;
			i++,j--;
		}
		else{
			if(k[i].d!=k[j].d)cnt+=k[j].c;
			k[i].c-=k[j].c;
			j--;
		}
	}cout<<cnt;
	return 0;
} 
