#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[200005];
int n,m;
int maxn;
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		int maxx=-1;
		for(int i=1;i<=n;i++){
			maxx=max(maxx,a[i]);
		}
		cout<<maxx;
		return 0;
	}
	else if(m==2){
		int maxx=-1;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				maxx=max(maxx,(a[i]&a[j]));
			}
		}
		cout<<maxx;
		return 0;
	}
	else if(m==n){
		int ans=a[1];
		for(int i=2;i<=n;i++){
			ans=(ans&a[i]);
		}
		cout<<ans;
		return 0;
	}else if(m==3){
		int maxx=-1;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int h=j+1;h<=n;h++){
					maxx=max(maxx,(a[i]&a[j]&a[h]));
				}
			}
		}
		cout<<maxx;
		return 0;
	}else if(m==4){
		int maxx=-1;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int h=j+1;h<=n;h++){
					for(int k=h+1;k<=n;k++){
						maxx=max(maxx,(a[i]&a[j]&a[h]&a[k]));
					}
				}
			}
		}
		cout<<maxx;
		return 0;
	}else if(m==5){
		int maxx=-1;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int h=j+1;h<=n;h++){
					for(int k=h+1;k<=n;k++){
						for(int p=k+1;p<=n;p++){
							maxx=max(maxx,(a[i]&a[j]&a[h]&a[k]&a[p]));
						}
					}
				}
			}
		}
		cout<<maxx;
		return 0;
	}else if(m==6){
		int maxx=-1;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int h=j+1;h<=n;h++){
					for(int k=h+1;k<=n;k++){
						for(int p=k+1;p<=n;p++){
							for(int q=p+1;q<=n;q++){
								maxx=max(maxx,(a[i]&a[j]&a[h]&a[k]&a[p]&a[q]));
							}
						}
					}
				}
			}
		}
		cout<<maxx;
		return 0;
	}else if(m==7){
		int maxx=-1;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int h=j+1;h<=n;h++){
					for(int k=h+1;k<=n;k++){
						for(int p=k+1;p<=n;p++){
							for(int q=p+1;q<=n;q++){
								for(int w=q+1;w<=n;w++){
									maxx=max(maxx,(a[i]&a[j]&a[h]&a[k]&a[p]&a[q]&a[w]));
								}
							}
						}
					}
				}
			}
		}
		cout<<maxx;
		return 0;
	}else if(m==8){
		int maxx=-1;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int h=j+1;h<=n;h++){
					for(int k=h+1;k<=n;k++){
						for(int p=k+1;p<=n;p++){
							for(int q=p+1;q<=n;q++){
								for(int w=q+1;w<=n;w++){
									for(int e=w+1;e<=n;e++){
										maxx=max(maxx,(a[i]&a[j]&a[h]&a[k]&a[p]&a[q]&a[w]&a[e]));
									}
								}
							}
						}
					}
				}
			}
		}
		cout<<maxx;
		return 0;
	}else if(m==9){
		int maxx=-1;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int h=j+1;h<=n;h++){
					for(int k=h+1;k<=n;k++){
						for(int p=k+1;p<=n;p++){
							for(int q=p+1;q<=n;q++){
								for(int w=q+1;w<=n;w++){
									for(int e=w+1;e<=n;e++){
										for(int r=e+1;r<=n;r++){
											maxx=max(maxx,(a[i]&a[j]&a[h]&a[k]&a[p]&a[q]&a[w]&a[e]&a[r]));
										}
									}
								}
							}
						}
					}
				}
			}
		}
		cout<<maxx;
		return 0;
	}else if(m==10){
		int maxx=-1;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int h=j+1;h<=n;h++){
					for(int k=h+1;k<=n;k++){
						for(int p=k+1;p<=n;p++){
							for(int q=p+1;q<=n;q++){
								for(int w=q+1;w<=n;w++){
									for(int e=w+1;e<=n;e++){
										for(int r=e+1;r<=n;r++){
											for(int t=r+1;t<=n;t++){
												maxx=max(maxx,(a[i]&a[j]&a[h]&a[k]&a[p]&a[q]&a[w]&a[e]&a[r]&a[t]));
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
		cout<<maxx;
		return 0;
	}else if(m==11){
		int maxx=-1;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int h=j+1;h<=n;h++){
					for(int k=h+1;k<=n;k++){
						for(int p=k+1;p<=n;p++){
							for(int q=p+1;q<=n;q++){
								for(int w=q+1;w<=n;w++){
									for(int e=w+1;e<=n;e++){
										for(int r=e+1;r<=n;r++){
											for(int t=r+1;t<=n;t++){
												for(int y=t+1;y<=n;y++){
													maxx=max(maxx,(a[i]&a[j]&a[h]&a[k]&a[p]&a[q]&a[w]&a[e]&a[r]&a[t]&a[y]));
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
		cout<<maxx;
		return 0;
	}else if(m==12){
		int maxx=-1;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int h=j+1;h<=n;h++){
					for(int k=h+1;k<=n;k++){
						for(int p=k+1;p<=n;p++){
							for(int q=p+1;q<=n;q++){
								for(int w=q+1;w<=n;w++){
									for(int e=w+1;e<=n;e++){
										for(int r=e+1;r<=n;r++){
											for(int t=r+1;t<=n;t++){
												for(int y=t+1;y<=n;y++){
													for(int u=y+1;u<=n;u++){
														maxx=max(maxx,(a[i]&a[j]&a[h]&a[k]&a[p]&a[q]&a[w]&a[e]&a[r]&a[t]&a[y]&a[u]));
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
		cout<<maxx;
		return 0;
	}else if(m==13){
		int maxx=-1;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int h=j+1;h<=n;h++){
					for(int k=h+1;k<=n;k++){
						for(int p=k+1;p<=n;p++){
							for(int q=p+1;q<=n;q++){
								for(int w=q+1;w<=n;w++){
									for(int e=w+1;e<=n;e++){
										for(int r=e+1;r<=n;r++){
											for(int t=r+1;t<=n;t++){
												for(int y=t+1;y<=n;y++){
													for(int u=y+1;u<=n;u++){
														for(int o=u+1;o<=n;o++){
															maxx=max(maxx,(a[i]&a[j]&a[h]&a[k]&a[p]&a[q]&a[w]&a[e]&a[r]&a[t]&a[y]&a[u]&a[o]));
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
		}
		cout<<maxx;
		return 0;
	}else if(m==14){
		int maxx=-1;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int h=j+1;h<=n;h++){
					for(int k=h+1;k<=n;k++){
						for(int p=k+1;p<=n;p++){
							for(int q=p+1;q<=n;q++){
								for(int w=q+1;w<=n;w++){
									for(int e=w+1;e<=n;e++){
										for(int r=e+1;r<=n;r++){
											for(int t=r+1;t<=n;t++){
												for(int y=t+1;y<=n;y++){
													for(int u=y+1;u<=n;u++){
														for(int o=u+1;o<=n;o++){
															for(int s=o+1;s<=n;s++){
																maxx=max(maxx,(a[i]&a[j]&a[h]&a[k]&a[p]&a[q]&a[w]&a[e]&a[r]&a[t]&a[y]&a[u]&a[o]&a[s]));
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
			}
		}
		cout<<maxx;
		return 0;
	}else if(m==15){
		int maxx=-1;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int h=j+1;h<=n;h++){
					for(int k=h+1;k<=n;k++){
						for(int p=k+1;p<=n;p++){
							for(int q=p+1;q<=n;q++){
								for(int w=q+1;w<=n;w++){
									for(int e=w+1;e<=n;e++){
										for(int r=e+1;r<=n;r++){
											for(int t=r+1;t<=n;t++){
												for(int y=t+1;y<=n;y++){
													for(int u=y+1;u<=n;u++){
														for(int o=u+1;o<=n;o++){
															for(int s=o+1;s<=n;s++){
																for(int d=s+1;d<=n;d++){
																	maxx=max(maxx,(a[i]&a[j]&a[h]&a[k]&a[p]&a[q]&a[w]&a[e]&a[r]&a[t]&a[y]&a[u]&a[o]&a[s]&a[d]));
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
				}
			}
		}
		cout<<maxx;
		return 0;
	}else if(m==16){
		int maxx=-1;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int h=j+1;h<=n;h++){
					for(int k=h+1;k<=n;k++){
						for(int p=k+1;p<=n;p++){
							for(int q=p+1;q<=n;q++){
								for(int w=q+1;w<=n;w++){
									for(int e=w+1;e<=n;e++){
										for(int r=e+1;r<=n;r++){
											for(int t=r+1;t<=n;t++){
												for(int y=t+1;y<=n;y++){
													for(int u=y+1;u<=n;u++){
														for(int o=u+1;o<=n;o++){
															for(int s=o+1;s<=n;s++){
																for(int d=s+1;d<=n;d++){
																	for(int f=d+1;f<=n;f++){
																		maxx=max(maxx,(a[i]&a[j]&a[h]&a[k]&a[p]&a[q]&a[w]&a[e]&a[r]&a[t]&a[y]&a[u]&a[o]&a[s]&a[d]&a[f]));
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
					}
				}
			}
		}
		cout<<maxx;
		return 0;
	}else if(m==17){
		int maxx=-1;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int h=j+1;h<=n;h++){
					for(int k=h+1;k<=n;k++){
						for(int p=k+1;p<=n;p++){
							for(int q=p+1;q<=n;q++){
								for(int w=q+1;w<=n;w++){
									for(int e=w+1;e<=n;e++){
										for(int r=e+1;r<=n;r++){
											for(int t=r+1;t<=n;t++){
												for(int y=t+1;y<=n;y++){
													for(int u=y+1;u<=n;u++){
														for(int o=u+1;o<=n;o++){
															for(int s=o+1;s<=n;s++){
																for(int d=s+1;d<=n;d++){
																	for(int f=d+1;f<=n;f++){
																		for(int g=f+1;g<=n;g++){
																			maxx=max(maxx,(a[i]&a[j]&a[h]&a[k]&a[p]&a[q]&a[w]&a[e]&a[r]&a[t]&a[y]&a[u]&a[o]&a[s]&a[d]&a[f]&a[g]));
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
						}
					}
				}
			}
		}
		cout<<maxx;
		return 0;
	}else if(m==18){
		int maxx=-1;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int h=j+1;h<=n;h++){
					for(int k=h+1;k<=n;k++){
						for(int p=k+1;p<=n;p++){
							for(int q=p+1;q<=n;q++){
								for(int w=q+1;w<=n;w++){
									for(int e=w+1;e<=n;e++){
										for(int r=e+1;r<=n;r++){
											for(int t=r+1;t<=n;t++){
												for(int y=t+1;y<=n;y++){
													for(int u=y+1;u<=n;u++){
														for(int o=u+1;o<=n;o++){
															for(int s=o+1;s<=n;s++){
																for(int d=s+1;d<=n;d++){
																	for(int f=d+1;f<=n;f++){
																		for(int g=f+1;g<=n;g++){
																			for(int l=g+1;l<=n;l++){
																				maxx=max(maxx,(a[i]&a[j]&a[h]&a[k]&a[p]&a[q]&a[w]&a[e]&a[r]&a[t]&a[y]&a[u]&a[o]&a[s]&a[d]&a[f]&a[g]&a[l]));
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
							}
						}
					}
				}
			}
		}
		cout<<maxx;
		return 0;
	}else if(m==19){
		int maxx=-1;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int h=j+1;h<=n;h++){
					for(int k=h+1;k<=n;k++){
						for(int p=k+1;p<=n;p++){
							for(int q=p+1;q<=n;q++){
								for(int w=q+1;w<=n;w++){
									for(int e=w+1;e<=n;e++){
										for(int r=e+1;r<=n;r++){
											for(int t=r+1;t<=n;t++){
												for(int y=t+1;y<=n;y++){
													for(int u=y+1;u<=n;u++){
														for(int o=u+1;o<=n;o++){
															for(int s=o+1;s<=n;s++){
																for(int d=s+1;d<=n;d++){
																	for(int f=d+1;f<=n;f++){
																		for(int g=f+1;g<=n;g++){
																			for(int l=g+1;l<=n;l++){
																				for(int z=l+1;z<=n;z++){
																					maxx=max(maxx,(a[i]&a[j]&a[h]&a[k]&a[p]&a[q]&a[w]&a[e]&a[r]&a[t]&a[y]&a[u]&a[o]&a[s]&a[d]&a[f]&a[g]&a[l]&a[z]));
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
								}
							}
						}
					}
				}
			}
		}
		cout<<maxx;
		return 0;
	}
	return 0;
}
