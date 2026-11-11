#include<bits/stdc++.h>
using namespace std;
string s1;
long long n,l1,l2,p=1,sum=0;
char b[200000005],d[200000005];
char hvc(char f[]){
	for(int i=1;i<=l2;i++){
		b[l1-i+1]=f[i];
	}
	for(int i=1;i<=l1;i++){
		return b[i];
	}
}
struct string{
	int a;
	char c;
}str[200000005];
int main(){
        freopen("string.in","r",stdin);
        freopen("string.out","w",stdout);
        cin>>n;
        for(int i=1;i<=n;i++){
			cin>>str[i].a>>str[i].c;
			l1+=str[i].a;
			for(int j=1;j<=str[i].a;j++){
				b[p]=str[i].c;
				d[p]=b[p];
				p++;
			}
		}
		if(l1%2==0) l2=l1/2;
		else l2=l1/2+1;
		for(int i=1;i<=l2;i++){
			hvc(b);
		}
		for(int i=1;i<=l1;i++){
			if(d[i]!=b[i]) sum++;
		}
		cout<<sum;
        return 0;
}
