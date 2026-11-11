#include <bits/stdc++.h>
using namespace std;
const int N=2e5+62;
int n;
long long s=0;
struct data{
	long long a;
	char c;
}b[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		cin>>b[i].a>>b[i].c;
	}
	for(int i=1,j=n;i<j;){
		if(b[i].a==b[j].a){
			if(b[i].c!=b[j].c){
				s+=b[i].a;
			}
			i++;
			j--;
		}
		else if(b[i].a>b[j].a){
			if(b[i].c!=b[j].c){
				b[i].a-=b[j].a;
				s+=b[j].a;
			}
			j--;
		}
		else if(b[i].a<b[j].a){
			if(b[i].c!=b[j].c){
				b[j].a-=b[i].a;
				s+=b[i].a;
			}
			i++;
		}
	}
	cout<<s;
	fclose(stdin);
	fclose(stdout);
    return 0;
} 
