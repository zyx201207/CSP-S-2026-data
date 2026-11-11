#include<bits/stdc++.h>
using namespace std;
char a[200000001]={0},b[200001]={0},c[200001]={0};
long long n,num=0,s,g=0,cnt=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	char d;
	for(long long i=0;i<n;i++){
		cin>>s>>d;
		for(int f=0;f<s;f++){
			a[num]=d;
			num++;
		}
	}
	long long o=num;
	if(o%2==1){
		g=1;
	}
	for(int i=0;i<(o+1)/2;i++){
			b[i]=a[(o-g)/2-i];
			c[i]=a[(o-g)/2+i];
			b[i]!=c[i]?cnt++:cnt+=0;
	}
	cout<<cnt;
	return 0;//delete my freopen and all debug words;
}

