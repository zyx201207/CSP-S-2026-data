#include<bits/stdc++.h>
using namespace std;
int t,p,q;
long long num[200010],ans;
string l;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>t;
	q=t-1;
	for(int i=0;i<t;i++){
		cin>>num[i];
		string str;
		cin>>str;
		l+=str;
	}
	//for(int i=1;i<t;i++) num[i]+=num[i-1];
	while(p<q){
		if(l[p]!=l[q]){
			if(num[p]>num[q]){
				num[p]-=num[q];
				ans+=num[q];
				q--;
			}
			else if(num[p]<num[q]){
				num[q]-=num[p];
				ans+=num[p];
				p++;
			}
			else{
				ans+=num[p];
				p++;
				q--;
			}
		}
		else{
			if(num[p]>num[q]){
				num[p]-=num[q];
				q--;
			}
			else if(num[p]<num[q]){
				num[q]-=num[p];
				p++;
			}
			else{
				p++;
				q--;
			}
		}
		//cout<<p<<q<<endl;
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

