#include<bits/stdc++.h>
using namespace std;
struct node{
	long long v;
	char d;
}b[200005],x[100005],y[100005];
long long n,a,s,ans,z;
char c;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>c;
		if(c==b[s].d){
			b[s].v+=a;
		}
		else{
			s++;
			b[s].v=a;
			b[s].d=c;
		}
		z+=a;
	}
	if(s==1){
		cout<<0;
	}
	else{
		long long i=1,j=s;
		while(i<j){
			long long le=0;
			j++;
			while(le<b[i].v){
				j--;
				le+=b[j].v;
				if(b[j].d!=b[i].d){
					if(b[i].v<le){
						ans+=b[i].v-le+b[j].v;
						b[j].v=le-b[i].v;
					}
					else{
						ans+=b[j].v;
						b[j].d=b[i].d;
					}
				}
			}
			if(b[j].d==b[i].d){
				b[j].v=le-b[i].v;
			}
		}
		cout<<ans;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

