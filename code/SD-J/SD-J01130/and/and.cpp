#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	int z[200001];
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>z[i];
	}
	int mzn=-1;
	if(m==1){
		sort(z+1,z+n+1);
		cout<<z[n];
	}else if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				if(z[i]&z[j]>mzn) mzn=z[i]&z[j];
			}
		}
		cout<<mzn;
	}else if(m==3){
		for(int a=1;a<=n;a++){
			for(int b=a;b<=n;b++){
				for(int c=b;c<=n;c++){
					if(z[a]&z[b]&z[c]>mzn) mzn=z[a]&z[b]&z[c];
				}
			}
		}
		cout<<mzn;
	}else if(m==4){
		for(int a=1;a<=n;a++){
			for(int b=a;b<=n;b++){
				for(int c=b;c<=n;c++){
					for(int d=c;d<=n;d++){
						if(z[a]&z[b]&z[c]&z[d]>mzn) mzn=z[a]&z[b]&z[c]&z[d];
					}
				}
			}
		}
		cout<<mzn;
	}else if(m==5){
		for(int a=1;a<=n;a++){
			for(int b=a;b<=n;b++){
				for(int c=b;c<=n;c++){
					for(int d=c;d<=n;d++){
						for(int e=d;e<=n;e++){
							if(z[a]&z[b]&z[c]&z[d]&z[e]>mzn) mzn=z[a]&z[b]&z[c]&z[d]&z[e];
						}
					}
				}
			}
		}
		cout<<mzn;
	}else if(m==6){
		for(int a=1;a<=n;a++){
			for(int b=a;b<=n;b++){
				for(int c=b;c<=n;c++){
					for(int d=c;d<=n;d++){
						for(int e=d;e<=n;e++){
							for(int f=e;f<=n;f++){
								if(z[a]&z[b]&z[c]&z[d]&z[e]&z[f]>mzn) mzn=z[a]&z[b]&z[c]&z[d]&z[e]&z[f];
							}
						}
					}
				}
			}
		}
		cout<<mzn;
	}else if(m==n-1){
		for(int i=1;i<=n;i++){
			int w=z[1];
			for(int j=2;j<=n;j++){
				if(j==i) continue;
				w&=z[j];
			}
			if(w>mzn) mzn=w;
		}
		cout<<mzn;
	}else if(m==n-2){
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				int w=z[1];
				for(int k=2;k<=n;k++){
					if(k==i||k==j) continue;
					w&=z[k];
				}
				if(w>mzn) mzn=w;
			}
		}
		cout<<mzn;
	}else if(m==n-3){
		for(int a=1;a<=n;a++){
			for(int b=a;b<=n;b++){
				for(int c=b;c<=n;c++){
					int w=z[1];
					for(int i=2;i<=n;i++){
						if(i==a||i==b||i==c) continue;
						w&=z[i];
					}
					if(w>mzn) mzn=w;
				}
			}
		}
		cout<<mzn;
	}else if(m==n-4){
		for(int a=1;a<=n;a++){
			for(int b=a;b<=n;b++){
				for(int c=b;c<=n;c++){
					for(int d=c;d<=n;d++){
						int w=z[1];
						for(int i=2;i<=n;i++){
							if(i==a||i==b||i==c||i==d) continue;
							w&=z[i];
						}
						if(w>mzn) mzn=w;
					}
				}
			}
		}
		cout<<mzn;
	}else if(m==n-5){
		for(int a=1;a<=n;a++){
			for(int b=a;b<=n;b++){
				for(int c=b;c<=n;c++){
					for(int d=c;d<=n;d++){
						for(int e=d;e<=n;e++){
							int w=z[1];
							for(int i=2;i<=n;i++){
								if(i==a||i==b||i==c||i==d||i==e) continue;
								w&=z[i];
							}
							if(w>mzn) mzn=w;
						}
					}
				}
			}
		}
		cout<<mzn;
	}
	return 0;
}
