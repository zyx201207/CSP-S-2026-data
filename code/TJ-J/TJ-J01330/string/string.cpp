#include<bits/stdc++.h>
using namespace std;
int n,a,d,l,ct;
char b;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	vector<char> c,e,f;
	cin>>n;
	for(int i=0;i<n;i++){
        scanf("%d %s",&a,&b);
		for(int j=0;j<a;j++){
			c[d]=b;
			d++;
		}
	}
	int len=c.size();
	l=len/2;
	for(int i=0;i<l;i++){
		e[i]=c[i-1];
	}
	for(int i=0;i<l;i++){
		f[i]=c[len-i];
	}
	for(int i=0;i<l;i++){
		if(e[i]!=f[i]) ct++;
	}
	printf("%d",ct);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
