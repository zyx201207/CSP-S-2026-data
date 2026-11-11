#include<bits/stdc++.h>

using namespace std;

int a[100000000];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++){
		scanf("%d",a+i); 
	}
	
	int maxa=0;
		
	if(m==1){
		for(int i=0;i<n;i++){
			if(a[i]>maxa)maxa=a[i];		
		}
		printf("%d",maxa);
		return 0;
	}
	if(m==2){ 
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				if(a[i]&a[j]>maxa)maxa = a[i]&a[j];
			}
		}
		printf("%d",maxa);
		return 0;
	}
	if(m==3){ 
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				for(int z=j+1;z<n;z++){
					if(a[i]&a[j]&a[z]>maxa)maxa	= a[i]&a[j]&a[z];
				}	
			}
		}
		printf("%d",maxa);
		return 0;
	}
	if(m==4){ 
		for(int a1=0;a1<n;a1++){
			for(int b=a1+1;b<n;b++){
				for(int c=b+1;c<n;c++){
					for(int d=c+1;d<n;d++){
						if(a[a1]&a[b]&a[c]&a[d]>maxa)maxa = a[a1]&a[b]&a[c]&a[d];
					}
				}
			}
		}
		printf("%d",maxa);
		return 0;
	}if(m==5){ 
		for(int a1=0;a1<n;a1++){
			for(int b=a1+1;b<n;b++){
				for(int c=b+1;c<n;c++){
					for(int d=c+1;d<n;d++){
						for(int e=d+1;e<n;e++){
							if(a[a1]&a[b]&a[c]&a[d]&a[e]>maxa)maxa = a[a1]&a[b]&a[c]&a[d]&a[e];
						}
					}
				}
			}
		}
		printf("%d",maxa);
		return 0;
	}if(m==6){ 
		for(int a1=0;a1<n;a1++){
			for(int b=a1+1;b<n;b++){
				for(int c=b+1;c<n;c++){
					for(int d=c+1;d<n;d++){
						for(int e=d+1;e<n;e++){
							for(int f=e+1;f<n;f++){
								if(a[a1]&a[b]&a[c]&a[d]&a[e]&a[f]>maxa)maxa = a[a1]&a[b]&a[c]&a[d]&a[e]&a[f];
							}
						}
					}
				}
			}
		}
		printf("%d",maxa);
		return 0;
	}if(m==7){ 
		for(int a1=0;a1<n;a1++){
			for(int b=a1+1;b<n;b++){
				for(int c=b+1;c<n;c++){
					for(int d=c+1;d<n;d++){
						for(int e=d+1;e<n;e++){
							for(int f=e+1;f<n;f++){
								for(int g=f+1;g<n;g++){
									if(a[a1]&a[b]&a[c]&a[d]&a[e]&a[f]&a[g]>maxa)maxa = a[a1]&a[b]&a[c]&a[d]&a[e]&a[f]&a[g];
								}
							}
						}
					}
				}
			}
		}
		printf("%d",maxa);
		return 0;
	}if(m==8){ 
		for(int a1=0;a1<n;a1++){
			for(int b=a1+1;b<n;b++){
				for(int c=b+1;c<n;c++){
					for(int d=c+1;d<n;d++){
						for(int e=d+1;e<n;e++){
							for(int f=e+1;f<n;f++){
								for(int g=f+1;g<n;g++){
									for(int h=g+1;h<n;h++){
										if(a[a1]&a[b]&a[c]&a[d]&a[e]&a[f]&a[g]&a[h]>maxa)maxa = a[a1]&a[b]&a[c]&a[d]&a[e]&a[f]&a[g]&a[h];	
										}
									}
								}
							}
						}
					}
				}
			}
		
		printf("%d",maxa);
		return 0;
	}if(m==9){ 
		for(int a1=0;a1<n;a1++){
			for(int b=a1+1;b<n;b++){
				for(int c=b+1;c<n;c++){
					for(int d=c+1;d<n;d++){
						for(int e=d+1;e<n;e++){
							for(int f=e+1;f<n;f++){
								for(int g=f+1;g<n;g++){
									for(int h=g+1;h<n;h++){
										for(int i=g+1;i<n;i++){
											if(a[a1]&a[b]&a[c]&a[d]&a[e]&a[f]&a[g]&a[h]&a[i]>maxa)maxa = a[a1]&a[b]&a[c]&a[d]&a[e]&a[f]&a[g]&a[h]&a[i];	
											
										}
									}
								}
							}
						}
					}
				}
			}
		}
		printf("%d",maxa);
		return 0;
	}if(m==10){ 
		for(int a1=0;a1<n;a1++){
			for(int b=a1+1;b<n;b++){
				for(int c=b+1;c<n;c++){
					for(int d=c+1;d<n;d++){
						for(int e=d+1;e<n;e++){
							for(int f=e+1;f<n;f++){
								for(int g=f+1;g<n;g++){
									for(int h=g+1;h<n;h++){
										for(int i=g+1;i<n;i++){
											for(int j=i+1;j<n;j++){
															if(a[a1]&a[b]&a[c]&a[d]&a[e]&a[f]&a[g]&a[h]&a[i]&a[j]>maxa)maxa = a[a1]&a[b]&a[c]&a[d]&a[e]&a[f]&a[g]&a[h]&a[i]&a[j];
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
		printf("%d",maxa);
		return 0;
	}if(m==11){ 
		for(int a1=0;a1<n;a1++){
			for(int b=a1+1;b<n;b++){
				for(int c=b+1;c<n;c++){
					for(int d=c+1;d<n;d++){
						for(int e=d+1;e<n;e++){
							for(int f=e+1;f<n;f++){
								for(int g=f+1;g<n;g++){
									for(int h=g+1;h<n;h++){
										for(int i=g+1;i<n;i++){
											for(int j=i+1;j<n;j++){
												for(int k=j+1;k<n;k++){
															if(a[a1]&a[b]&a[c]&a[d]&a[e]&a[f]&a[g]&a[h]&a[i]&a[j]&a[k]>maxa)maxa = a[a1]&a[b]&a[c]&a[d]&a[e]&a[f]&a[g]&a[h]&a[i]&a[j]&a[k];
														
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
		printf("%d",maxa);
		return 0;
	}if(m==12){ 
		for(int a1=0;a1<n;a1++){
			for(int b=a1+1;b<n;b++){
				for(int c=b+1;c<n;c++){
					for(int d=c+1;d<n;d++){
						for(int e=d+1;e<n;e++){
							for(int f=e+1;f<n;f++){
								for(int g=f+1;g<n;g++){
									for(int h=g+1;h<n;h++){
										for(int i=g+1;i<n;i++){
											for(int j=i+1;j<n;j++){
												for(int k=j+1;k<n;k++){
													for(int l=k+1;l<n;l++){
															if(a[a1]&a[b]&a[c]&a[d]&a[e]&a[f]&a[g]&a[h]&a[i]&a[j]&a[k]&a[l]>maxa)maxa = a[a1]&a[b]&a[c]&a[d]&a[e]&a[f]&a[g]&a[h]&a[i]&a[j]&a[k]&a[l];
														
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
		printf("%d",maxa);
		return 0;
	}if(m==13){ 
		for(int a1=0;a1<n;a1++){
			for(int b=a1+1;b<n;b++){
				for(int c=b+1;c<n;c++){
					for(int d=c+1;d<n;d++){
						for(int e=d+1;e<n;e++){
							for(int f=e+1;f<n;f++){
								for(int g=f+1;g<n;g++){
									for(int h=g+1;h<n;h++){
										for(int i=g+1;i<n;i++){
											for(int j=i+1;j<n;j++){
												for(int k=j+1;k<n;k++){
													for(int l=k+1;l<n;l++){
														for(int m1=l+1;m1<n;m1++){
															if(a[a1]&a[b]&a[c]&a[d]&a[e]&a[f]&a[g]&a[h]&a[i]&a[j]&a[k]&a[l]&a[m1]>maxa)maxa = a[a1]&a[b]&a[c]&a[d]&a[e]&a[f]&a[g]&a[h]&a[i]&a[j]&a[k]&a[l]&a[m1];
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
		printf("%d",maxa);
		return 0;
	}if(m==14){ 
		for(int a1=0;a1<n;a1++){
			for(int b=a1+1;b<n;b++){
				for(int c=b+1;c<n;c++){
					for(int d=c+1;d<n;d++){
						for(int e=d+1;e<n;e++){
							for(int f=e+1;f<n;f++){
								for(int g=f+1;g<n;g++){
									for(int h=g+1;h<n;h++){
										for(int i=g+1;i<n;i++){
											for(int j=i+1;j<n;j++){
												for(int k=j+1;k<n;k++){
													for(int l=k+1;l<n;l++){
														for(int m1=l+1;m1<n;m1++){
															for(int n1=m1+1;n1<n;n1++){
																						if(a[a1]&a[b]&a[c]&a[d]&a[e]&a[f]&a[g]&a[h]&a[i]&a[j]&a[k]&a[l]&a[m1]&a[n1]>maxa)maxa = a[a1]&a[b]&a[c]&a[d]&a[e]&a[f]&a[g]&a[h]&a[i]&a[j]&a[k]&a[l]&a[m1]&a[n1];
																	
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
		printf("%d",maxa);
		return 0;
	}if(m==15){ 
		for(int a1=0;a1<n;a1++){
			for(int b=a1+1;b<n;b++){
				for(int c=b+1;c<n;c++){
					for(int d=c+1;d<n;d++){
						for(int e=d+1;e<n;e++){
							for(int f=e+1;f<n;f++){
								for(int g=f+1;g<n;g++){
									for(int h=g+1;h<n;h++){
										for(int i=g+1;i<n;i++){
											for(int j=i+1;j<n;j++){
												for(int k=j+1;k<n;k++){
													for(int l=k+1;l<n;l++){
														for(int m1=l+1;m1<n;m1++){
															for(int n1=m1+1;n1<n;n1++){
																for(int o=n1+1;o<n;o++){
																						if(a[a1]&a[b]&a[c]&a[d]&a[e]&a[f]&a[g]&a[h]&a[i]&a[j]&a[k]&a[l]&a[m1]&a[n1]&a[o]>maxa)maxa = a[a1]&a[b]&a[c]&a[d]&a[e]&a[f]&a[g]&a[h]&a[i]&a[j]&a[k]&a[l]&a[m1]&a[n1]&a[o];
																	
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
		printf("%d",maxa);
		return 0;
	}if(m==16){ 
		for(int a1=0;a1<n;a1++){
			for(int b=a1+1;b<n;b++){
				for(int c=b+1;c<n;c++){
					for(int d=c+1;d<n;d++){
						for(int e=d+1;e<n;e++){
							for(int f=e+1;f<n;f++){
								for(int g=f+1;g<n;g++){
									for(int h=g+1;h<n;h++){
										for(int i=g+1;i<n;i++){
											for(int j=i+1;j<n;j++){
												for(int k=j+1;k<n;k++){
													for(int l=k+1;l<n;l++){
														for(int m1=l+1;m1<n;m1++){
															for(int n1=m1+1;n1<n;n1++){
																for(int o=n1+1;o<n;o++){
																	for(int p=o+1;p<n;p++){
																						if(a[a1]&a[b]&a[c]&a[d]&a[e]&a[f]&a[j]&a[h]&a[i]&a[j]&a[k]&a[l]&a[m1]&a[n1]&a[o]&a[p]>maxa)maxa = a[a1]&a[b]&a[c]&a[d]&a[e]&a[f]&a[g]&a[h]&a[i]&a[j]&a[k]&a[l]&a[m1]&a[n1]&a[o]&a[p];
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
		printf("%d",maxa);
		return 0;
	}if(m==17){ 
		for(int a1=0;a1<n;a1++){
			for(int b=a1+1;b<n;b++){
				for(int c=b+1;c<n;c++){
					for(int d=c+1;d<n;d++){
						for(int e=d+1;e<n;e++){
							for(int f=e+1;f<n;f++){
								for(int g=f+1;g<n;g++){
									for(int h=g+1;h<n;h++){
										for(int i=g+1;i<n;i++){
											for(int j=i+1;j<n;j++){
												for(int k=j+1;k<n;k++){
													for(int l=k+1;l<n;l++){
														for(int m1=l+1;m1<n;m1++){
															for(int n1=m1+1;n1<n;n1++){
																for(int o=n1+1;o<n;o++){
																	for(int p=o+1;p<n;p++){
																		for(int q=p+1;q<n;q++){
																						if(a[a1]&a[b]&a[c]&a[d]&a[e]&a[f]&a[g]&a[h]&a[i]&a[j]&a[k]&a[l]&a[m1]&a[n1]&a[o]&a[p]&a[q]>maxa)maxa = a[a1]&a[b]&a[c]&a[d]&a[e]&a[f]&a[g]&a[h]&a[i]&a[j]&a[k]&a[l]&a[m1]&a[n1]&a[o]&a[p]&a[q];
																					
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
		printf("%d",maxa);
		return 0;
	}if(m==18){ 
		for(int a1=0;a1<n;a1++){
			for(int b=a1+1;b<n;b++){
				for(int c=b+1;c<n;c++){
					for(int d=c+1;d<n;d++){
						for(int e=d+1;e<n;e++){
							for(int f=e+1;f<n;f++){
								for(int g=f+1;g<n;g++){
									for(int h=g+1;h<n;h++){
										for(int i=g+1;i<n;i++){
											for(int j=i+1;j<n;j++){
												for(int k=j+1;k<n;k++){
													for(int l=k+1;l<n;l++){
														for(int m1=l+1;m1<n;m1++){
															for(int n1=m1+1;n1<n;n1++){
																for(int o=n1+1;o<n;o++){
																	for(int p=o+1;p<n;p++){
																		for(int q=p+1;q<n;q++){
																			for(int r=q+1;r<n;r++){
																						if(a[a1]&a[b]&a[c]&a[d]&a[e]&a[f]&a[g]&a[h]&a[i]&a[j]&a[k]&a[l]&a[m1]&a[n1]&a[o]&a[p]&a[q]&a[r]>maxa)maxa = a[a1]&a[b]&a[c]&a[d]&a[e]&a[f]&a[g]&a[h]&a[i]&a[j]&a[k]&a[l]&a[m1]&a[n1]&a[o]&a[p]&a[q]&a[r];
																					
																				
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
		
		printf("%d",maxa);
		return 0;
	}if(m==19){ 
		for(int a1=0;a1<n;a1++){
			for(int b=a1+1;b<n;b++){
				for(int c=b+1;c<n;c++){
					for(int d=c+1;d<n;d++){
						for(int e=d+1;e<n;e++){
							for(int f=e+1;f<n;f++){
								for(int g=f+1;g<n;g++){
									for(int h=g+1;h<n;h++){
										for(int i=g+1;i<n;i++){
											for(int j=i+1;j<n;j++){
												for(int k=j+1;k<n;k++){
													for(int l=k+1;l<n;l++){
														for(int m1=l+1;m1<n;m1++){
															for(int n1=m1+1;n1<n;n1++){
																for(int o=n1+1;o<n;o++){
																	for(int p=o+1;p<n;p++){
																		for(int q=p+1;q<n;q++){
																			for(int r=q+1;r<n;r++){
																				for(int s=q+1;s<n;s++){
																					if(a[a1]&a[b]&a[c]&a[d]&a[e]&a[f]&a[g]&a[h]&a[i]&a[j]&a[k]&a[l]&a[m1]&a[n1]&a[o]&a[p]&a[q]&a[s]>maxa)maxa = a[a1]&a[b]&a[c]&a[d]&a[e]&a[f]&a[g]&a[h]&a[i]&a[j]&a[k]&a[l]&a[m1]&a[n1]&a[o]&a[p]&a[q]&a[s];
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

		printf("%d",maxa);
		return 0;
	}if(m==20){ 
		for(int a1=0;a1<n;a1++){
			for(int b=a1+1;b<n;b++){
				for(int c=b+1;c<n;c++){
					for(int d=c+1;d<n;d++){
						for(int e=d+1;e<n;e++){
							for(int f=e+1;f<n;f++){
								for(int g=f+1;g<n;g++){
									for(int h=g+1;h<n;h++){
										for(int i=g+1;i<n;i++){
											for(int j=i+1;j<n;j++){
												for(int k=j+1;k<n;k++){
													for(int l=k+1;l<n;l++){
														for(int m1=l+1;m1<n;m1++){
															for(int n1=m1+1;n1<n;n1++){
																for(int o=n1+1;o<n;o++){
																	for(int p=o+1;p<n;p++){
																		for(int q=p+1;q<n;q++){
																			for(int r=q+1;r<n;r++){
																				for(int s=q+1;s<n;s++){
																					for(int t=s+1;t<n;t++){
																						if(a[a1]&a[b]&a[c]&a[d]&a[e]&a[f]&a[j]&a[h]&a[i]&a[j]&a[k]&a[l]&a[m1]&a[n1]&a[o]&a[p]&a[q]&a[s]&a[t]>maxa)maxa = a[a1]&a[b]&a[c]&a[d]&a[e]&a[f]&a[g]&a[h]&a[i]&a[j]&a[k]&a[l]&a[m1]&a[n1]&a[o]&a[p]&a[q]&a[s]&a[t];
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
		}
		printf("%d",maxa);
		return 0;
	}
	return 0;
} /*
5 3
31 3 1 15 7
*/ 
