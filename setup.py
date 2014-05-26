from distutils.core import setup, Extension

extensions = [Extension('PySteamAPI',
				include_dirs = ['/usr/local/include'],
				libraries = ['steam_api'],
				library_dirs = ['/usr/local/lib'],
				sources = ['steam.cpp'])
			]

setup(name='PySteamAPI', version='1.0', ext_modules=extensions)