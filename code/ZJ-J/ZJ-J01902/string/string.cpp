#include <iostream>
using namespace std;
struct tmd{
	int a;
	char c;
};
tmd in[200001];
int n;
long long ans=0;
long long l=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>in[i].a>>in[i].c;
		l+=in[i].a;
	}
	int p=1,q=n;
	while (p!=q&&l!=1&&l!=0){
		if (in[p].c!=in[q].c){
			ans+=min(in[p].a,in[q].a);
		}
		in[p].a-=min(in[p].a,in[q].a);
		in[q].a-=min(in[p].a,in[q].a);
		l-=2*min(in[p].a,in[q].a);
		if (in[p].a==0){
			p++;
		}
		if (in[q].a==0){
			q--;
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}