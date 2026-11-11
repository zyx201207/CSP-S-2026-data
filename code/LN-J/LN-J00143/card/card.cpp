#include<bits/stdc++.h>
using namespace std;
string t,s="0";
int a[100000001],tong[1000001],b[100000001];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
    int n,m,max=-1;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
		cin>>t[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			s[i]=s[i]+t[j];
			for(int z=i;z<j;z++){
				if(s[z]==t[j]){
					for(int q=z;q<j;q++){
						s[q]=s[j-z+q];
					}
				}
			}
		}
		int len=s.size();
		for(int p=1;p<=len;p++){
			a[p]=s[p]-'0';
			tong[a[p]]++;
		}
		for(int f=1;f<=len;f++){
		     s[f]=0;
		}
	}
	for(int i=1;i<=100;i++){
		if(a[i]>max){
			max=a[i];
		}
	}
	for(int i=1;i<=max;i++){
			cout<<tong[i];
	}
    return 0;
}
