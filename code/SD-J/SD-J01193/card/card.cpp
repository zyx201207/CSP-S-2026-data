#include<bits/stdc++.h>
using namespace std;
int find(int b[1000],int n,int x){
	for(int i=0;i<n;i++){
		if(b[i]==x) return i;
	}
	return 0;
}
int main(){
	stack<int> st;
	//freopen("card.in","r",stdin);
	//freopen("card.out","w",stdout);
	long long n,m,cnt=0;
	cin>>n>>m;
	long long a[n],b[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int resultz[m];
	for(int i=0;i<n;i++){
		b[i]=a[i];
	}
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			if(find(b[n],i,j)>0){
				for(int z=0;z<j-find(b[n],i,j);z++){
					st.pop();
					break;
				}
			}
			st.push(b[i]);cnt++;
			
		}
	}
	//fclose(stdin);
	//fclose(stdout);
}

