#include <bits/stdc++.h>
using namespace std;
const int N=200005;
int n,m,ma;
int a[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		for(int i=1;i<=n;i++){
			int x=a[i]|0;
			ma=max(x,ma);
		}
		cout<<ma;
		return 0;
	}
	if(m==n){
		int x=a[1];
		for(int i=2;i<=n;i++){
			x&=a[i];
		}
		cout<<x;
		return 0;
	}
	if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				int x=a[i]&a[j];
				ma=max(x,ma);
			}
		}
		cout<<ma;
		return 0;
	}
	if(m==3){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int q=j+1;q<=n;q++){
					int x=a[i]&a[j]&a[q];
					ma=max(x,ma);
				}
			}
		}
		cout<<ma;
		return 0;
	}
	if(m==4){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int q=j+1;q<=n;q++){
					for(int p=q+1;p<=n;p++){
						int x=a[i]&a[j]&a[q]&a[p];
						ma=max(x,ma);
					}
				}
			}
		}
		cout<<ma;
		return 0;
	}if(m==5){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int q=j+1;q<=n;q++){
					for(int p=q+1;p<=n;p++){
						for(int r=p+1;r<=n;r++){
							int x=a[i]&a[j]&a[q]&a[p]&a[r];
							ma=max(x,ma);
						}
					}
				}
			}
		}
		cout<<ma;
		return 0;
	}
	if(m==6){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int q=j+1;q<=n;q++){
					for(int p=q+1;p<=n;p++){
						for(int r=p+1;r<=n;r++){
							for(int l=r+1;l<=n;l++){
								int x=a[i]&a[j]&a[q]&a[p]&a[r]&a[l];
								ma=max(x,ma);
							}
						}
					}
				}
			}
		}
		cout<<ma;
		return 0;
	}
	if(m==7){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int q=j+1;q<=n;q++){
					for(int p=q+1;p<=n;p++){
						for(int r=p+1;r<=n;r++){
							for(int l=r+1;l<=n;l++){
								for(int o=l+1;o<=n;o++){
									int x=a[i]&a[j]&a[q]&a[p]&a[r]&a[l]&a[o];
									ma=max(x,ma);
								}
							}
						}
					}
				}
			}
		}
		cout<<ma;
		return 0;
	}
	if(m==8){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int q=j+1;q<=n;q++){
					for(int p=q+1;p<=n;p++){
						for(int r=p+1;r<=n;r++){
							for(int l=r+1;l<=n;l++){
								for(int o=l+1;o<=n;o++){
									for(int h=o+1;h<=n;h++){
										int x=a[i]&a[j]&a[q]&a[p]&a[r]&a[l]&a[o]&a[h];
										ma=max(x,ma);
									}
								}
							}
						}
					}
				}
			}
		}
		cout<<ma;
		return 0;
	}
	if(m==9){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int q=j+1;q<=n;q++){
					for(int p=q+1;p<=n;p++){
						for(int r=p+1;r<=n;r++){
							for(int l=r+1;l<=n;l++){
								for(int o=l+1;o<=n;o++){
									for(int h=o+1;h<=n;h++){
										for(int k=h+1;k<=n;k++){
											int x=a[i]&a[j]&a[q]&a[p]&a[r]&a[l]&a[o]&a[h]&a[k];
											ma=max(x,ma);
										}
									}
								}
							}
						}
					}
				}
			}
		}
		cout<<ma;
		return 0;
	}
	if(m==10){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int q=j+1;q<=n;q++){
					for(int p=q+1;p<=n;p++){
						for(int r=p+1;r<=n;r++){
							for(int l=r+1;l<=n;l++){
								for(int o=l+1;o<=n;o++){
									for(int h=o+1;h<=n;h++){
										for(int k=h+1;k<=n;k++){
											for(int f=k+1;f<=n;f++){
												int x=a[i]&a[j]&a[q]&a[p]&a[r]&a[l]&a[o]&a[h]&a[k]&a[f];
												ma=max(x,ma);
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
		cout<<ma;
		return 0;
	}
	if(m==11){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int q=j+1;q<=n;q++){
					for(int p=q+1;p<=n;p++){
						for(int r=p+1;r<=n;r++){
							for(int l=r+1;l<=n;l++){
								for(int o=l+1;o<=n;o++){
									for(int h=o+1;h<=n;h++){
										for(int k=h+1;k<=n;k++){
											for(int f=k+1;f<=n;f++){
												for(int v=f+1;v<=n;v++){
													int x=a[i]&a[j]&a[q]&a[p]&a[r]&a[l]&a[o]&a[h]&a[k]&a[f]&a[v];
													ma=max(x,ma);
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
		cout<<ma;
		return 0;
	}
	if(m==12){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int q=j+1;q<=n;q++){
					for(int p=q+1;p<=n;p++){
						for(int r=p+1;r<=n;r++){
							for(int l=r+1;l<=n;l++){
								for(int o=l+1;o<=n;o++){
									for(int h=o+1;h<=n;h++){
										for(int k=h+1;k<=n;k++){
											for(int f=k+1;f<=n;f++){
												for(int v=f+1;v<=n;v++){
													for(int z=v+1;z<=n;z++){
														int x=a[i]&a[j]&a[q]&a[p]&a[r]&a[l]&a[o]&a[h]&a[k]&a[f]&a[v]&a[z];
														ma=max(x,ma);
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
		cout<<ma;
		return 0;
	}
	return 0;
}
