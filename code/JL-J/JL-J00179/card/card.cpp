#include<bits/stdc++.h>
using namespace std;
stack<int> s,ss;
int c[500005],t[300005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int a,b,ok2=1,zzz=0;
    cin>>a>>b;
    for(int i=1;i<=a;i++){
		scanf("%d",&c[i]);
		if(c[i]<zzz) ok2=0;
		zzz=c[i];
	}
	if(ok2){
		for(int i=1;i<=b;i++) cout<<i<<" ";
		return 0;
	}
    for(int i=1;i<=a;i++){
		int ok;
		for(int j=i;j<=a;j++){
			ok=1;
			while(!s.empty()){
				ss.push(s.top()),s.pop();
				if(ss.top()==c[j]){
					ok=0;
					break;
				}
			}
			while(!ss.empty()){
				if(ok) s.push(ss.top());
				ss.pop();
			}
			s.push(c[j]);
		}
		while(!s.empty()) t[s.top()]++,s.pop();
	}
	for(int i=1;i<=b;i++) printf("%d ",t[i]);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
