#include<bits/stdc++.h>
using namespace std;
int s[200003];
char z[200003];
int q[200003];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>s[i]>>z[i];
		if(i==0){
			q[i]+=s[i];
			//cout<<q[i]<<endl;
			continue;
		}
		q[i]=q[i-1]+s[i];
		/*if(z[i]==z[i-1]){qu chong
			i--;wo bu hui aaa
			s[i]+=s[i+1];
			q[i]=q[i+1];	
		}*/
		//cout<<q[i]<<endl;
	}
	int f=0,hi=0,wi=q[n-1],hgi=0,wgi=n-1;
	char h=z[0],w=z[n-1];
	while(hi<wi){
		//cout<<"pan duan"<<" "<<h<<" "<<w<<endl;
		if(h!=w){
			//cout<<"diff"<<endl;
			f++;
		}
		hi++;
		wi--;
		if(hi>=q[hgi]){
			hgi++;
			h=z[hgi];
			//cout<<"shou->"<<h<<"  "<<i<<endl;
		}
		if(wi<=q[wgi-1]){
			wgi--;
			w=z[wgi];
			//cout<<"wei->"<<w<<"  "<<i<<endl;
		}
	}
	cout<<f;
	return 0;
}
