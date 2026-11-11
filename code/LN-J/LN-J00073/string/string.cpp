#include<bits/stdc++.h>
using namespace std;
struct chuan{
	long long ch;
	string zi;
};
long long n,ans,a;
string c,l;
chuan shu[200003];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
cin>>n;
for(int i=1;i<=n;i++){
	cin>>a>>c;
	shu[i].ch=a;
	shu[i].zi=c;
		
		}

	int duanz=1,duany=n;
	long long i=1,j=shu[duany].ch;
	while(duanz<duany||duanz==duany&&i<j){
		if(shu[duanz].zi!=shu[duany].zi) ans++;
		if(ans==2000000) cout<<duanz<<" "<<i<<" "<<duany<<" "<<j;
		i++;
		j--;
		if(i>shu[duanz].ch){
			duanz++;
			i=1;
		}
		if(j<1){
			duany--;
			j=shu[duany].ch;
		}
	}

cout<<ans;
return 0;
}

