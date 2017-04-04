from distutils.core import setup, Extension

extensions = [Extension('PySteamAPI',
				include_dirs = ['/usr/local/include'],
				library_dirs = ['/usr/local/lib', './libsteam_api/osx32'],
				libraries = ['steam_api'],
				sources = ['steam.cpp'])
			]

setup(name='PySteamAPI', version='1.0', ext_modules=extensions)